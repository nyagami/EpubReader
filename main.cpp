#include <iostream>
#include <string>
#include <Epub.hpp>

#include <chrono>
#ifdef _WIN32
#include <windows.h>
#include <psapi.h>
size_t get_memory_usage_kb()
{
    PROCESS_MEMORY_COUNTERS info;
    GetProcessMemoryInfo(GetCurrentProcess(), &info, sizeof(info));
    return info.WorkingSetSize / 1024;
}
#else
#include <unistd.h>
#include <sys/resource.h>
size_t get_memory_usage_kb()
{
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
#if defined(__APPLE__) && defined(__MACH__)
    return usage.ru_maxrss / 1024; // macOS: bytes to KB
#else
    return usage.ru_maxrss; // Linux: already in KB
#endif
}
#endif

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        cout << "Not enough arguments" << endl;
        return 1;
    }
    auto start = chrono::high_resolution_clock::now();

    // --- YOUR EPUB PARSING CODE HERE ---
    // zip_open, parse OPF, extract metadata...
    string epub_path = argv[1];

    EpubMetadata metadata = parseEpub(epub_path);

    auto end = chrono::high_resolution_clock::now();
    auto ms = chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    size_t memory_kb = get_memory_usage_kb();

    // Output
    cout << "Name: " << metadata.name << "\n"
         << "Author: " << metadata.author << "\n"
         << "Artist: " << metadata.artist << "\n"
         << "Summary: " << metadata.summary << "\n"
         << "Cover: " << metadata.cover << "\n\n";

    cout << "Chapters:\n";
    for (const auto &ch : metadata.chapters)
        cout << " - [" << ch.name << "] " << ch.path << "\n";

    cout << "\nCSS Files:\n";
    for (const auto &css : metadata.cssPaths)
        cout << " - " << css << "\n";

        cout << "\nImage Files:\n";
    for (const auto &img : metadata.imagePaths)
        cout << " - " << img << "\n";

    cout << "\nTime: " << ms << " ms\n";
    cout << "Peak memory usage: " << memory_kb << " KB\n";

    return 0;
}
