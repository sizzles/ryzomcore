IF(WITH_STATIC_DRIVERS)
  ADD_DEFINITIONS(-DNL_STATIC)
ENDIF()

IF(WIN32)
  # On Win32 we can also build the MAX plugins.
  IF(WITH_NEL_MAXPLUGIN)
    FIND_PACKAGE(3dsMaxSDK)
  ENDIF()
ENDIF()

IF(WITH_3D)
  FIND_PACKAGE(FreeType)

  IF(WITH_NEL_CEGUI)
    FIND_PACKAGE(CEGUI)
  ENDIF()
ENDIF()

IF(WITH_SOUND)
  FIND_PACKAGE(Ogg)
  FIND_PACKAGE(Vorbis)

  IF(WITH_DRIVER_OPENAL)
    FIND_PACKAGE(OpenAL)
  ENDIF()

  IF(WITH_DRIVER_FMOD)
    FIND_PACKAGE(FMOD)
  ENDIF()
ENDIF()

IF(WITH_GTK)
  FIND_PACKAGE(GTK2)
ENDIF()

IF(WITH_INSTALL_LIBRARIES)
  IF(UNIX)
    SET(prefix ${CMAKE_INSTALL_PREFIX})
    SET(exec_prefix ${NL_BIN_ABSOLUTE_PREFIX})
    SET(libdir ${NL_LIB_ABSOLUTE_PREFIX})
    SET(includedir ${CMAKE_INSTALL_PREFIX}/include)
    SET(enable_ligo ${WITH_LIGO})
    SET(enable_logic ${WITH_LOGIC})
    SET(enable_georges ${WITH_GEORGES})
    SET(enable_net ${WITH_NET})
    SET(enable_3d ${WITH_3D})
    SET(enable_pacs ${WITH_PACS})
    SET(enable_sound ${WITH_SOUND})
    CONFIGURE_FILE(nel-config.in ${CMAKE_CURRENT_BINARY_DIR}/nel-config)

    INSTALL(PROGRAMS ${CMAKE_CURRENT_BINARY_DIR}/nel-config DESTINATION ${NL_BIN_PREFIX})
  ENDIF()

  ADD_SUBDIRECTORY(include)
ENDIF()

ADD_SUBDIRECTORY(src)

IF(WITH_NEL_SAMPLES)
  ADD_SUBDIRECTORY(samples)
ENDIF()

ADD_SUBDIRECTORY(tools)
