find src/ -name '*.h' -exec clang-tidy -fix -fix-errors {} -- -x c++ -std=c++17 \;
