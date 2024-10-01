//#include <jni.h>
//#include <string>
//#include <fstream>
//#include <sstream>
//
//extern "C" JNIEXPORT jstring JNICALL
//Java_com_root_jnidetection_MainActivity_getProcSelfMaps(JNIEnv* env, jobject /* this */) {
//    std::ifstream mapsFile("/proc/self/maps");
//    if (!mapsFile.is_open()) {
//        return env->NewStringUTF("Failed to open /proc/self/maps");
//    }
//
//    std::stringstream buffer;
//    buffer << mapsFile.rdbuf();  // Read the entire file into the buffer
//    std::string mapsContent = buffer.str();
//
//    // Close the file
//    mapsFile.close();
//
//    // Return the content of /proc/self/maps as a Java string
//    return env->NewStringUTF(mapsContent.c_str());
//}


//
//#include <jni.h>
//#include <string>
//#include <fstream>
//#include <sstream>
//#include <android/log.h>
//
//// Define a log tag
//#define LOG_TAG "JNIDetection"
//#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
//
//extern "C" JNIEXPORT jstring JNICALL
//Java_com_root_jnidetection_MainActivity_getProcSelfMaps(JNIEnv* env, jobject instance, jstring filePath) {
//    // Open /proc/self/maps
//    std::ifstream mapsFile("/proc/self/maps");
//    if (!mapsFile.is_open()) {
//        return env->NewStringUTF("Failed to open /proc/self/maps");
//    }
//
//    // Read the entire file into a string buffer
//    std::stringstream buffer;
//    buffer << mapsFile.rdbuf();
//    std::string mapsContent = buffer.str();
//
//    // Close /proc/self/maps
//    mapsFile.close();
//
//    // Get the file path from the Java argument
//    const char *filePathCStr = env->GetStringUTFChars(filePath, nullptr);
//    if (!filePathCStr) {
//        return env->NewStringUTF("Failed to retrieve file path");
//    }
//
//    // Try to save the content into the specified file
//    std::ofstream outputFile(filePathCStr);
//    if (!outputFile.is_open()) {
//        env->ReleaseStringUTFChars(filePath, filePathCStr);
//        return env->NewStringUTF("Failed to open output file");
//    }
//
//    // Write the maps content to the file
//    outputFile << mapsContent;
//
//    // Close the output file
//    outputFile.close();
//
//    // Release the file path string
//    env->ReleaseStringUTFChars(filePath, filePathCStr);
//
//    // Log success message
//    LOGI("Successfully wrote /proc/self/maps to %s", filePathCStr);
//
//    // Return the maps content to display in the EditText
//    return env->NewStringUTF(mapsContent.c_str());
//}



//
//#include <jni.h>
//#include <fstream>
//#include <sstream>
//#include <iostream>
//#include <string>
//#include <vector>
//#include <android/log.h>
//#include <stdio.h>
//
//#define LOG_TAG "JNI_LOG"
//#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)
//
//extern "C"
//JNIEXPORT jstring JNICALL
//Java_com_root_jnidetection_MainActivity_getProcSelfMaps(JNIEnv *env, jobject obj) {
//    std::ifstream mapsFile("/proc/self/maps");
//    std::string line;
//    std::string result = "";
//
//    if (!mapsFile.is_open()) {
//        LOGE("Could not open /proc/self/maps");
//        return env->NewStringUTF("Error opening /proc/self/maps");
//    }
//
//    // Filtered content
//    std::vector<std::string> filteredLines;
//
//    // Read the maps file line by line
//    while (std::getline(mapsFile, line)) {
//        // Check if the line contains r-xp or r--p
//        if (line.find("r-xp") != std::string::npos || line.find("r--p") != std::string::npos) {
//            filteredLines.push_back(line);
//            result += line + "\n";  // Append filtered line to result
//        }
//    }
//
//    mapsFile.close();
//
//    // Save filtered result to a file in internal storage
//    std::ofstream outputFile;
//    std::string filePath = "/data/data/com.root.jnidetection/files/maps.txt";  // Ensure your package name is correct
//    outputFile.open(filePath);
//
//    if (outputFile.is_open()) {
//        for (const std::string& filteredLine : filteredLines) {
//            outputFile << filteredLine << "\n";
//        }
//        outputFile.close();
//    } else {
//        LOGE("Could not open output file to save filtered maps data.");
//    }
//
//    return env->NewStringUTF(result.c_str());  // Return the result to display in EditText
//}
//
//extern "C" JNIEXPORT jstring JNICALL
//Java_com_root_jnidetection_MainActivity_getDex2OatFlags(JNIEnv *env, jobject /* this */) {
//    // Command to run
//    const char *command = "getprop | grep dalvik.vm.dex2oat-flags";
//
//    // Buffer to hold the output
//    char buffer[128];
//    std::string result = "";
//
//    // Open the process using popen (process open)
//    FILE *pipe = popen(command, "r");
//    if (!pipe) {
//        return env->NewStringUTF("Error running command");
//    }
//
//    // Read the output of the command
//    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
//        result += buffer;
//    }
//
//    // Close the process
//    pclose(pipe);
//
//    // Return the result back to Java as a jstring
//    return env->NewStringUTF(result.c_str());
//}
//
//

#include <jni.h>
#include <string>
#include <android/log.h>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <vector>
#include <sys/system_properties.h>

#define LOG_TAG "ROOT_CHECK"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#define LOG_TAG "JNI_LOG"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

// Method to get content from /proc/self/maps
extern "C"
JNIEXPORT jstring JNICALL
Java_com_root_jnidetection_MainActivity_getProcSelfMaps(JNIEnv *env, jobject obj) {
    std::ifstream mapsFile("/proc/self/maps");
    std::string line;
    std::string result = "";

    if (!mapsFile.is_open()) {
        LOGE("Could not open /proc/self/maps");
        return env->NewStringUTF("Error opening /proc/self/maps");
    }
    // Filtered content
    char value[PROP_VALUE_MAX];

    int len = __system_property_get("sys.oem_unlock_allowed", value);

    std::vector<std::string> filteredLines;

    // Read the maps file line by line and filter based on r-xp and r--p
    while (std::getline(mapsFile, line)) {
        line+="oem: "+len;
        if (line.find("r-xp") != std::string::npos || line.find("r--p") != std::string::npos) {
            filteredLines.push_back(line);
            result += line + "\n";  // Append filtered line to result
        }
    }

    mapsFile.close();

    // Save filtered result to a file in internal storage
    std::ofstream outputFile;
    std::string filePath = "/data/data/com.root.jnidetection/files/maps.txt";  // Ensure your package name is correct
    outputFile.open(filePath);

    if (outputFile.is_open()) {
        for (const std::string& filteredLine : filteredLines) {
            outputFile << filteredLine << "\n";
        }
        outputFile.close();
    } else {
        LOGE("Could not open output file to save filtered maps data.");
    }

    return env->NewStringUTF(result.c_str());  // Return the result to display in EditText
}

// Method to get result from `getprop | grep dalvik.vm.dex2oat-flags`
extern "C"
JNIEXPORT jstring JNICALL
Java_com_root_jnidetection_MainActivity_getDex2OatFlags(JNIEnv *env, jobject obj) {
    // Command to execute
   // const char* command = "getprop | grep dalvik.vm.dex2oat-flags";
    const char* command = "getprop | grep -e init.svc -e stopped -e [[:upper:]] -e [[:lower:]] -e [[:digit:]]";



    // Open a pipe to run the command
    FILE *pipe = popen(command, "r");
    if (!pipe) {
        LOGE("Failed to run command: %s", command);
        return env->NewStringUTF("Error executing command");
    }

    // Read the output of the command into a string
    std::stringstream result;
    char buffer[128];
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result << buffer;
    }

    // Close the pipe
    pclose(pipe);

    return env->NewStringUTF(result.str().c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_root_jnidetection_MainActivity_checkSuBinary(JNIEnv *env, jobject obj) {
    // List of common paths to check for the 'su' binary
    std::vector<std::string> suPaths = {
            "/system/bin/su",
            "/system/xbin/su",
            "/data/local/xbin/su",
            "/data/local/bin/su",
            "/sbin/su",
            "/su/bin/su",
            "/vendor/bin/su",
            "/data/local/",
            "/data/local/bin/",
            "/data/local/xbin/",
            "/sbin/",
            "/su/bin/",
            "/system/bin/",
            "/system/bin/.ext/",
            "/system/bin/failsafe/",
            "/system/sd/xbin/",
            "/system/usr/we-need-root/",
            "/system/xbin/",
            "/cache/",
            "/dev/",
            "/system",
            "/system/bin",
            "/system/sbin",
            "/system/xbin",
            "/vendor/bin"
    };
    std::string result;
    bool suFound = false;

    // Iterate through each path and check if the 'su' binary exists
    for (const std::string& path : suPaths) {
        std::ifstream file(path);
        if (file.good()) {
            suFound = true;
            result += "su binary found at: " + path + "\n";  // Append each path
            LOGI("su binary found at: %s", path.c_str());
        }
        file.close();
    }

    // If no 'su' binary was found
    if (!suFound) {
        result = "No su binary found in common paths.";
        LOGI("No su binary found.");
    }

    // Return the result to be displayed in the EditText
    return env->NewStringUTF(result.c_str());
}