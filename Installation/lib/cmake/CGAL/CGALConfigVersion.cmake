set(CGAL_MAJOR_VERSION 4)
set(CGAL_MINOR_VERSION 14)
set(CGAL_BUGFIX_VERSION 4)
set(CGAL_VERSION_PUBLIC_RELEASE_VERSION "4.14.4")
set(CGAL_VERSION_PUBLIC_RELEASE_NAME "CGAL-${CGAL_VERSION_PUBLIC_RELEASE_VERSION}")

if (CGAL_BUGFIX_VERSION AND CGAL_BUGFIX_VERSION GREATER 0)
  set(CGAL_CREATED_VERSION_NUM "${CGAL_MAJOR_VERSION}.${CGAL_MINOR_VERSION}.${CGAL_BUGFIX_VERSION}")
else()
  set(CGAL_CREATED_VERSION_NUM "${CGAL_MAJOR_VERSION}.${CGAL_MINOR_VERSION}")
endif()

set(PACKAGE_VERSION ${CGAL_CREATED_VERSION_NUM})

if(PACKAGE_VERSION VERSION_LESS PACKAGE_FIND_VERSION)
  set(PACKAGE_VERSION_COMPATIBLE FALSE)
else()
  if(PACKAGE_FIND_VERSION_MAJOR STREQUAL CGAL_MAJOR_VERSION)
    set(PACKAGE_VERSION_COMPATIBLE TRUE)
  else()
    set(PACKAGE_VERSION_COMPATIBLE FALSE)
  endif()
  if(PACKAGE_FIND_VERSION STREQUAL PACKAGE_VERSION)
    set(PACKAGE_VERSION_EXACT TRUE)
  endif()
endif()
