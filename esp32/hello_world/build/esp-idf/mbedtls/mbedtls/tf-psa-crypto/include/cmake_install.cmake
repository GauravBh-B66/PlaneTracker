# Install script for directory: /gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "TRUE")
endif()

# Set path to fallback-tool for dependency-resolution.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/gsFiles/user_gs/home_user_gsb/.espressif/tools/xtensa-esp-elf/esp-15.2.0_20251204/xtensa-esp-elf/bin/xtensa-esp32-elf-objdump")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/psa" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_adjust_auto_enabled.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_adjust_config_dependencies.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_adjust_config_derived.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_adjust_config_key_pair_types.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_adjust_config_synonyms.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_builtin_composites.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_builtin_key_derivation.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_builtin_primitives.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_compat.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_config.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_driver_common.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_driver_contexts_composites.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_driver_contexts_key_derivation.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_driver_contexts_primitives.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_driver_random.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_extra.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_platform.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_sizes.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_struct.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_types.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/psa/crypto_values.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/tf-psa-crypto" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/tf-psa-crypto/build_info.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/tf-psa-crypto/version.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/mbedtls" TYPE FILE PERMISSIONS OWNER_READ OWNER_WRITE GROUP_READ WORLD_READ FILES
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/../drivers/builtin/include/mbedtls/config_adjust_legacy_crypto.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/../drivers/builtin/include/mbedtls/private_access.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/mbedtls/asn1.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/mbedtls/asn1write.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/mbedtls/base64.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/mbedtls/compat-3-crypto.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/mbedtls/constant_time.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/mbedtls/lms.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/mbedtls/md.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/mbedtls/memory_buffer_alloc.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/mbedtls/nist_kw.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/mbedtls/pem.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/mbedtls/pk.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/mbedtls/platform.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/mbedtls/platform_time.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/mbedtls/platform_util.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/mbedtls/psa_util.h"
    "/gsFiles/Projects/tools/esp/v6.0.1/esp-idf/components/mbedtls/mbedtls/tf-psa-crypto/include/mbedtls/threading.h"
    )
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
if(CMAKE_INSTALL_LOCAL_ONLY)
  file(WRITE "/gsFiles/Projects/esp32/hello_world/build/esp-idf/mbedtls/mbedtls/tf-psa-crypto/include/install_local_manifest.txt"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
endif()
