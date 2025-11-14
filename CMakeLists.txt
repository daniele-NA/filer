cmake_minimum_required(VERSION 3.31)
project(filer LANGUAGES C CXX)

set(CMAKE_C_STANDARD 17)


add_executable(filer main.c
        util/dotenv/dotenv.c
        data/api/api.c
        data/file/txt_file_actions.c
)

#Le librerie extra vanno linkate

target_link_libraries(
        filer PUBLIC -lcurl
)