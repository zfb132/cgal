#include <CGAL/basic.h>
#include <CGAL/Polynomial.h>
#include <CGAL/Polynomial_traits_d.h>
#include <CGAL/Polynomial_type_generator.h>

int main(){
  typedef CGAL::Polynomial<int>        Poly_int_1;
  typedef CGAL::Polynomial<Poly_int_1> Poly_int_2;
  typedef CGAL::Polynomial<Poly_int_2> Poly_int_3;
  
  {
    typedef CGAL::Polynomial_type_generator<int,1>::Type Polynomial;
    BOOST_STATIC_ASSERT((::boost::is_same<Polynomial, Poly_int_1>::value)); 
  } 
  {
    typedef CGAL::Polynomial_type_generator<int,2>::Type Polynomial;
    BOOST_STATIC_ASSERT((::boost::is_same<Polynomial, Poly_int_2>::value)); 
  } 
  {
    typedef CGAL::Polynomial_type_generator<int,3>::Type Polynomial;
    BOOST_STATIC_ASSERT((::boost::is_same<Polynomial, Poly_int_3>::value)); 
  }
}