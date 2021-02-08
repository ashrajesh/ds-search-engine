cmake_minimum_required(VERSION 3.15)
project(search-engine-ashwin-rajesh)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS_DEBUG  "-O3")

add_executable(search-engine-ashwin-rajesh main.cpp document_parser.cpp document_parser.h hash_table.h word.cpp word.h keyhash.h hashnode.h tree_two.h simdjson.h simdjson.cpp AVLSuperRoot.h query.cpp query.h hashread.cpp hashread.h porter2_stemmer.cpp porter2_stemmer.h hash.h string_view.h stopwords.txt User_Interface.cpp User_Interface.h)