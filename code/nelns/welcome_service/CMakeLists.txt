FILE(GLOB SRC *.cpp *.h)

ADD_EXECUTABLE(welcome_service WIN32 ${SRC})

INCLUDE_DIRECTORIES(${NELMISC_INCLUDE_DIRS})

TARGET_LINK_LIBRARIES(welcome_service
						nelmisc
						nelnet)

NL_DEFAULT_PROPS(welcome_service "NeLNS, Services: Welcome Service")
NL_ADD_RUNTIME_FLAGS(welcome_service)

INSTALL(TARGETS welcome_service RUNTIME DESTINATION sbin COMPONENT ws)
INSTALL(FILES welcome_service.cfg common.cfg DESTINATION ${NL_ETC_PREFIX}/nelns COMPONENT ws)
