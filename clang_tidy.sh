find src/ -name '*.h' -exec clang-tidy {} -- -x c++ -std=c++17 \;
