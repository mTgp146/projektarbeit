cmake_minimum_required (VERSION 3.9)
project (asteroids)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_compile_options(-g -Wall -Wextra -Wpedantic -Wl,--stack,16777216)

enable_testing()
add_executable(game_test game_test.cpp model.cpp models/galaxip.cpp models/projectile.cpp models/green_alien.cpp models/blue_alien.cpp models/red_alien.cpp models/flagship.cpp models/alien.cpp models/background.cpp models/backgroundParticle.cpp models/sounds.cpp models/points.cpp)
target_link_libraries(game_test gtest gtest_main SDL2 SDL2_mixer)

