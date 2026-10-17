# Add your executable from the local files
add_executable(ZombieTown ZombieTown.cpp ZombieTown.h)

# Link Raylib to it
target_link_libraries(ZombieTown PRIVATE raylib)