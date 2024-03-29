#  ASIO_FOUND: True if asio was found
#  ASIO_INCLUDE_DIR:  The asio include dir
#

set(ASIO_SEARCH_PATH_LIST
        ${ASIO_HOME}
        $ENV{ASIO_HOME}
        ${ASIO_DIR}
        /usr/local
        /opt
        /usr
        )

find_path(ASIO_INCLUDE_DIR asio.hpp
        HINTS ${ASIO_SEARCH_PATH_LIST}
        PATH_SUFFIXES include
        DOC "Find the asio includes"
        )

set(ASIO_INCLUDE_DIRS ${ASIO_INCLUDE_DIR})

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(ASIO
        REQUIRED_VARS ASIO_INCLUDE_DIRS
        )