# Add your executable from the local files
add_executable(ZombieTown ZombieTown.cpp ZombieTown.h Entity.cpp Entity.h)

# Link Raylib to it
target_link_libraries(ZombieTown PRIVATE raylib)