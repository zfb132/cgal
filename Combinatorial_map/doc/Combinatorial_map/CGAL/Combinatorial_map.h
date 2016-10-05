
namespace CGAL {

/*!
\ingroup PkgCombinatorialMapsClasses

The class `Combinatorial_map` represents a <I>d</I>D combinatorial map.

Darts and non void attributes are stored in memory using `Compact_container`, using `Alloc` as allocator.

\cgalModels `CombinatorialMap`

\tparam d the dimension of the map.

\tparam Items a model of the `GenericMapItems` concept. Equal to `Combinatorial_map_min_items<d>` by default.

\tparam Alloc has to match the standard allocator requirements. The `rebind` mechanism  `Alloc` will be used to create appropriate allocators internally with value type `Dart`. Equal to `CGAL_ALLOCATOR(int)` from `<CGAL/memory.h>` by default.

\cgalHeading{Complexity}

The complexity of \link GenericMap::sew `sew`\endlink and \link GenericMap::unsew `unsew`\endlink is in <I>O</I>( \f$ | \f$ <I>S</I> \f$ | \f$ \f$ \times\f$\f$ | \f$ <I>c</I> \f$ | \f$ ), <I>S</I> being the set of darts of the orbit \f$ \langle{}\f$\f$ \beta_1\f$,\f$ \ldots\f$,\f$ \beta_{i-2}\f$,\f$ \beta_{i+2}\f$,\f$ \ldots\f$,\f$ \beta_d\f$\f$ \rangle{}\f$ for the considered dart, and <I>c</I> the biggest <I>j</I>-cell merged or split during the sew such that <I>j</I>-attributes are non void. The complexity of \link GenericMap::is_sewable `is_sewable`\endlink is in <I>O</I>( \f$ | \f$ <I>S</I> \f$ | \f$ ).

The complexity of \link GenericMap::set_attribute `set_attribute`\endlink is in <I>O</I>( \f$ | \f$ <I>c</I> \f$ | \f$ ), <I>c</I> being the <I>i</I>-cell containing the considered dart.

The complexity of \link GenericMap::is_without_boundary(unsigned int i) const `is_without_boundary(i)`\endlink is in <I>O</I>( \f$ | \f$ <I>D</I> \f$ | \f$ ), <I>D</I> being the set of darts of the combinatorial map, and the complexity of \link GenericMap::is_without_boundary() const `is_without_boundary()`\endlink is in <I>O</I>( \f$ | \f$ <I>D</I> \f$ | \f$ \f$ \times\f$ <I>d</I> ).

The complexity of \link GenericMap::unmark_all `unmark_all`\endlink and \link GenericMap::free_mark `free_mark`\endlink is in <I>O</I>( 1 ) if all the darts of the combinatorial map have the same mark, and in <I>O</I>( \f$ | \f$ <I>D</I> \f$ | \f$ ) otherwise.

The complexity of \link GenericMap::is_valid `is_valid`\endlink is in <I>O</I>( \f$ | \f$ <I>D</I> \f$ | \f$ \f$ \times\f$ <I>d</I>\f$ ^2\f$ ).

The complexity of \link GenericMap::clear `clear`\endlink is in <I>O</I>( \f$ | \f$ <I>D</I> \f$ | \f$ \f$ \times\f$ <I>d</I> ).

Other methods have all a constant time complexity.

\sa `GenericMapItems`
\sa `Dart`

*/
template< unsigned int d, typename Items, typename Alloc >
class Combinatorial_map {
public:

/// \name Constants
/// @{

/*!
The dimension of the combinatorial map.
*/
static const unsigned int dimension = d;

/// @}

/// \name Types
/// @{

/*!

*/
typedef Combinatorial_map<d,Items,Alloc> Self;

/*!

*/
typedef Items::Dart_wrapper<Self>::Dart Dart;

/// @}

}; /* end Combinatorial_map */
} /* end namespace CGAL */
