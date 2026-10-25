# Fahrenheit to Celsius File Converter (C++)

## Summary
This program converts temperatures from Fahrenheit to Celsius using file input and output. It reads a list of cities and their Fahrenheit temperatures from `FahrenheitTemperature.txt`, converts each temperature with the formula `(F - 32) * 5 / 9`, and writes each city with its Celsius temperature to `CelsiusTemperature.txt`. It solves the problem of converting a whole list of temperatures automatically instead of by hand, and it shows how a program can work with data stored in files.

## What I Did Well
I checked that both files opened before using them. If the input file is missing or the output file can't be created, the program prints a clear message and exits with an error code instead of failing silently. I also closed the input file before exiting when the output file failed to open, so nothing was left open. The read loop (`while (inFS >> city >> fahrenheit)`) handles any number of lines and stops at the end of the file. I used `5.0 / 9.0` so the division is done with decimals, because `5 / 9` with integers would equal 0 and make every result wrong.

## Areas for Enhancement
- **Input validation:** The program assumes every line has a city name and a whole number. If a line were malformed, the loop would stop early without telling the user. I could check for bad data and report which line was wrong.
- **Flexibility:** The file names are hard-coded. I could let the user pass them in as command-line arguments or type them in, so the program works with other files without changing the code. This would also reduce the file path problems I ran into.
- **Data type:** Temperatures are read as `int`, so a value like 72.5 would not be read correctly. Using `double` would fix that.
- **Output formatting:** The Celsius values print with default precision. Using `fixed` and `setprecision(1)` would make the output consistent and easier to read.
- **Style:** I used `using namespace std;`. In a larger project, I would write `std::` explicitly to avoid name conflicts.
- **Structure:** I could move the conversion into its own function, for example `double toCelsius(double f)`, so it can be reused and tested separately.

## Challenges and How I Overcame Them
The hardest part of this project was figuring out where a problem was and then fixing it. My program kept printing "Could not open FahrenheitTemperature.txt," and I struggled with it because the code looked correct, so I wasn't sure where the problem was. I learned that the program looks for the file in its working directory, and my text file was not in the same folder as the program. I moved the file into the right folder and double-checked the spelling and the extension, since a file can accidentally end up named something like `FahrenheitTemperature.txt.txt`. This is why I added the `is_open()` check with a clear error message: now the program tells me what is wrong instead of failing silently.

To track down problems, I test with small inputs, read error messages carefully, and check the simple things first, like file names and locations. I'm adding cppreference.com, my instructor, my classmates, and a debugger to my support network.

## Transferable Skills
- Reading from and writing to files, which is useful in almost any program that handles data
- Error checking, so programs fail safely and clearly
- Debugging: narrowing a problem down to the exact line or step that causes it
- Translating a formula or requirement into working code
- Skills that apply in other languages in this course, such as Java and Python, because file handling and loops work in similar ways

## Maintainability, Readability, and Adaptability
I added comments explaining each step, including what `ifstream` and `ofstream` are and where the conversion formula comes from. Variable names like `fahrenheit`, `celsius`, `inFS`, and `outFS` describe what they hold. The code is organized in a clear order: open files, check them, process the data, close files. The program works with any number of records, so it adapts to larger input files without changes. With a few small changes, such as the function and command-line file names listed above, it would be even easier to extend.
