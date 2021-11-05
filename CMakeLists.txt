cmake_minimum_required(VERSION 3.0.0)
project(VirtualArtist VERSION 0.1.0)
set(CMAKE_CXX_COMPILER g++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

include_directories(VirtualArtist 

                    inc/core
                    inc/gui

                    inc/core/low_level_layer               

                    inc/gui/graphic
                    inc/gui/commands
                    
                    inc/tools)

add_executable(VirtualArtist 
                
                # main
                src/main.cpp
                
                # low level layer
                src/core/low_level_layer/display.cpp
                src/core/low_level_layer/simple_text.cpp
                src/core/low_level_layer/surface.cpp
                src/core/low_level_layer/hardware_event.cpp
                
                src/core/field.cpp
                
                # gui
                # ...graphic
                src/gui/graphic/filled_circle.cpp
                src/gui/graphic/filled_rectangle.cpp
                src/gui/graphic/text.cpp
                src/gui/graphic/graphic_frame.cpp
                src/gui/graphic/drawable_texture.cpp
                
                #...commands
                src/gui/commands/paint_canvas.cpp
                
                src/gui/widget.cpp
                src/gui/software_event.cpp
                src/gui/canvas.cpp
)

target_link_libraries(VirtualArtist SDL2 SDL2_image SDL2_ttf)