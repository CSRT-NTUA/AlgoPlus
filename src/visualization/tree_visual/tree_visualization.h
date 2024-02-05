#ifdef __cplusplus
#include <chrono>
#include <fstream>
#include <iostream>
#include <string>
#endif

using namespace std;

#define OPEN_COMMAND "open"

// COLORS FOR TEXT

namespace visualization {

const char *reset = "\033[0m";
const char *black = "\033[30m";
const char *red = "\033[31m";
const char *green = "\033[32m";
const char *yellow = "\033[33m";
const char *blue = "\033[34m";
const char *magenta = "\033[35m";
const char *cyan = "\033[36m";
const char *white = "\033[37m";

const char *blackBackground = "\033[40m";
const char *redBackground = "\033[41m";
const char *greenBackground = "\033[42m";
const char *yellowBackground = "\033[43m";
const char *blueBackground = "\033[44m";
const char *magentaBackground = "\033[45m";
const char *cyanBackground = "\033[46m";
const char *whiteBackground = "\033[47m";

const char *bold = "\033[1m";
const char *underline = "\033[4m";
const char *blink = "\033[5m";
const char *inverse = "\033[7m";

void visualize(std::string &__generate,
               std::string newFileName = "unnamed.dot") {
  auto start_time = std::chrono::high_resolution_clock::now();
  try {
    if (newFileName.size() < 5 ||
        newFileName.substr(newFileName.length() - 4) != ".dot")
      newFileName += ".dot";
    // newFileName = "examples/" + newFileName;
    //  Open the file for writing
    std::ofstream outFile(newFileName);

    // Check if the file is successfully opened
    if (outFile.is_open()) {
      // Write the DOT format header
      outFile << "digraph Tree {" << std::endl;

      // Generate DOT code recursively
      outFile << __generate;
      // Write the DOT format footer
      outFile << "}" << std::endl;

      // Close the file
      outFile.close();

      std::cout << green << "Visualization file '" << newFileName
                << "' created successfully." << std::endl
                << reset;
      auto end_time = std::chrono::high_resolution_clock::now();
      auto duration = std::chrono::duration_cast<std::chrono::microseconds>(
          end_time - start_time);
      double runtime_sec = static_cast<double>(duration.count()) / 1e6;

      std::cout << blue << "Visualization runtime: " << runtime_sec << " sec"
                << std::endl
                << reset;
      std::string openCommand = OPEN_COMMAND + std::string(" ") + newFileName;
      system(openCommand.c_str());
    } else {
      std::cerr << red << "Error: Unable to open file '" << newFileName
                << "' for writing." << std::endl
                << reset;
    }
  } catch (const std::exception &e) {
    std::cerr << red << "Error: " << e.what() << std::endl << reset;
  }
};

}; // namespace visualization
