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


#include <jni.h>
#include <sstream>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <unistd.h>
#include <cstdio>
#include <cstring>
#include <sstream>
#include <iostream>
#include <regex>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <sys/stat.h>

#include <sys/stat.h>

#define LOG_TAG "ROOT_CHECK"
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

#define LOG_TAG "JNI_LOG"
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

// Method to get content from /proc/self/maps
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
//    // Filtered content
//    char value[PROP_VALUE_MAX];
//
//    int len = __system_property_get("sys.oem_unlock_allowed", value);
//
//    std::vector<std::string> filteredLines;
//
//    // Read the maps file line by line and filter based on r-xp and r--p
//    while (std::getline(mapsFile, line)) {
//        line+="oem: "+len;
//        if (line.find("r-xp") != std::string::npos || line.find("r--p") != std::string::npos)
//        {
//            filteredLines.push_back(line);
//            result += line + "\n";  // Append filtered line to result
//        }
//    }
//
//    mapsFile.close();
//
//    // Save filtered result to a file in internal storage
//    std::ofstream outputFile;
//    std::string filePath ="/storage/emulated/0/Download/maps.txt";//"/data/data/com.root.jnidetection/files/maps.txt";  // Ensure your package name is correct
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



extern "C"
JNIEXPORT jstring JNICALL
Java_com_root_jnidetection_MainActivity_checkMagisk(JNIEnv *env, jobject obj) {
    std::ifstream mapsFile("/proc/self/mounts");
    std::string line;
    std::string result;

    if (!mapsFile.is_open()) {
        LOGE("Could not open /proc/self/mounts");
        return env->NewStringUTF("Error opening /proc/self/mounts");
    }

    // Read the maps file line by line
    while (std::getline(mapsFile, line)) {
        // Check if the line contains memfd:jit-cache
        if (line.find("magisk") != std::string::npos || (line.find("core/mirror") != std::string::npos && line.find("core/img") != std::string::npos))
        {
            result += line + "\n";  // Append the line containing memfd:jit-cache to the result
        }
    }

    mapsFile.close();

    // Check if any rows were found
    if (result.empty()) {
        return env->NewStringUTF("magisk not found in /proc/self/mounts\n");
    }

    // Return the result to display in the EditText
    return env->NewStringUTF(result.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_root_jnidetection_MainActivity_getProcSelfMaps(JNIEnv *env, jobject obj) {
    std::ifstream mapsFile("/proc/self/maps");
    std::string line;
    std::string result;

    if (!mapsFile.is_open()) {
        LOGE("Could not open /proc/self/maps");
        return env->NewStringUTF("Error opening /proc/self/maps");
    }

    // Read the maps file line by line
    while (std::getline(mapsFile, line)) {
        // Check if the line contains memfd:jit-cache
        if (line.find("memfd:jit-cache") != std::string::npos || (line.find(".so") != std::string::npos && line.find("x") != std::string::npos)) {
            result += line + "\n";  // Append the line containing memfd:jit-cache to the result
        }
    }

    mapsFile.close();

    // Check if any rows were found
    if (result.empty()) {
        return env->NewStringUTF("memfd:jit-cache not found in /proc/self/maps\n");
    }

    // Return the result to display in the EditText
    return env->NewStringUTF(result.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_root_jnidetection_MainActivity_checkDevBlock(JNIEnv *env, jobject obj) {
    // Command to execute 'ls -la /dev/block/'
    const char* command = "ls -la /dev/block/";

    // Buffer to hold the output
    char buffer[128];
    std::stringstream result;

    // Open the process using popen (process open)
    FILE* pipe = popen(command, "r");
    if (!pipe) {
        LOGE("Failed to run command: %s", command);
        return env->NewStringUTF("Error running command");
    }

    // Read the output of the command
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result << buffer;
    }

    // Close the process
    pclose(pipe);

    // Log the result for debugging
    LOGI("Command output: %s", result.str().c_str());

    // Prepare to return the output
    std::string output = result.str();
    std::string response;

    // Check if "radio" is in the output
    if (output.find("radio") != std::string::npos) {
        LOGI("user radio found.");
        response = "user radio found.\n";
    } else {
        LOGI("user radio not found.");
        response = "user radio not found.\n";
    }

    // Append the output from the ls command
    response += output;

    // Return the combined result to display in the EditText
    return env->NewStringUTF(response.c_str());
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_root_jnidetection_MainActivity_checkMountInfo(JNIEnv *env, jobject obj) {
    // Command to execute 'cat /proc/self/mountinfo | grep -i "mode=755"'
    const char* command = "cat /proc/self/mountinfo | grep -i \"mode=755\"";

    // Buffer to hold the output
    char buffer[128];
    std::stringstream result;

    // Open the process using popen (process open)
    FILE* pipe = popen(command, "r");
    if (!pipe) {
        LOGE("Failed to run command: %s", command);
        return env->NewStringUTF("Error running command");
    }

    // Read the output of the command
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result << buffer;
    }

    // Close the process
    pclose(pipe);

    // Log the result for debugging
    LOGI("Command output: %s", result.str().c_str());

    // Prepare the output to return
    std::string output = result.str();

    if (output.empty()) {
        // If the output is empty, return a "not found" message
        return env->NewStringUTF("No entries with mode=755 found.");
    } else {
        // Return the output of the grep command
        return env->NewStringUTF(output.c_str());
    }
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_root_jnidetection_MainActivity_listInstalledPackages(JNIEnv *env, jobject obj) {
    // Command to list all installed packages
    const char* command = "pm list packages|grep -i xxn";

    // Buffer to hold the output
    char buffer[128];
    std::stringstream result;

    // Open the process using popen (process open)
    FILE* pipe = popen(command, "r");
    if (!pipe) {
        LOGE("Failed to run command: %s", command);
        return env->NewStringUTF("Error running command");
    }

    // Read the output of the command
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result << buffer;
    }

    // Close the process
    pclose(pipe);

    // Log the result for debugging
    LOGI("Command output: %s", result.str().c_str());

    // Prepare the output to return
    std::string output = result.str();

    if (output.empty()) {
        // If the output is empty, return a "No output" message
        return env->NewStringUTF("No packages found.");
    } else {
        // Return the output of the pm list packages command
        return env->NewStringUTF(output.c_str());
    }
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_root_jnidetection_MainActivity_getFilteredPackages(JNIEnv *env, jobject obj) {
    const char* command = "pm list packages -i | grep -e \"installer=null\"";

    // Buffer to hold the output
    char buffer[128];
    std::stringstream result;

    // Open the process using popen (process open)
    FILE* pipe = popen(command, "r");
    if (!pipe) {
        LOGE("Failed to run command: %s", command);
        return env->NewStringUTF("Error running command");
    }

    // Read the output of the command
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result << buffer;
    }

    // Close the process
    pclose(pipe);

    // Convert the result to a string for further processing
    std::string output = result.str();

    // Log the result for debugging
    LOGI("All packages with null installer: %s", output.c_str());

    // Prepare to filter results
    std::stringstream filteredResult;
    std::string line;

    // Split the output into lines and filter for packages with exactly one dot
    std::istringstream outputStream(output);
    while (std::getline(outputStream, line)) {
        // Extract package name from the line
        size_t pos = line.find(':');
        if (pos != std::string::npos) {
            std::string packageName = line.substr(pos + 1); // Get the package name after '='

            // Split the package name by '.' and count the number of parts
            std::vector<std::string> parts;
            std::stringstream ss(packageName);
            std::string part;
            while (std::getline(ss, part, '.')) {
                parts.push_back(part);
            }

            // Check if there is exactly one dot (i.e., two parts)
            if (parts.size() == 2) {
                filteredResult << line << "\n"; // Append the line to the result
            }
        }
    }

    // Convert filtered result to string
    std::string filteredOutput = filteredResult.str();

    // Return a message if no packages matched the criteria
    if (filteredOutput.empty()) {
        return env->NewStringUTF("No packages found with null installer and one dot.");
    }

    // Log the filtered result for debugging
    LOGI("Filtered packages: %s", filteredOutput.c_str());

    // Return the filtered result to display in the EditText
    return env->NewStringUTF(filteredOutput.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_root_jnidetection_MainActivity_checkMounts(JNIEnv *env, jobject obj) {
    // Command to execute 'cat /proc/self/mountinfo | grep -i "mode=755"'
    const char* command = "cat /proc/mounts|grep -i magisk";

    // Buffer to hold the output
    char buffer[128];
    std::stringstream result;

    // Open the process using popen (process open)
    FILE* pipe = popen(command, "r");
    if (!pipe) {
        LOGE("Failed to run command: %s", command);
        return env->NewStringUTF("Error running command");
    }

    // Read the output of the command
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result << buffer;
    }

    // Close the process
    pclose(pipe);

    // Log the result for debugging
    LOGI("Command output: %s", result.str().c_str());

    // Prepare the output to return
    std::string output = result.str();

    if (output.empty()) {
        // If the output is empty, return a "not found" message
        return env->NewStringUTF("No entries mounts found.");
    } else {
        // Return the output of the grep command
        return env->NewStringUTF(output.c_str());
    }
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_root_jnidetection_MainActivity_checkSEpolocy(JNIEnv *env, jobject obj) {
    // Command to execute 'ls -la /dev/block/'
    const char* command = "ls -la /sys/fs/selinux/policy";

    // Buffer to hold the output
    char buffer[128];
    std::stringstream result;

    // Open the process using popen (process open)
    FILE* pipe = popen(command, "r");
    if (!pipe) {
        LOGE("Failed to run command: %s", command);
        return env->NewStringUTF("Error running command");
    }

    // Read the output of the command
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result << buffer;
    }

    // Close the process
    pclose(pipe);

    // Log the result for debugging
  //  LOGI("Command output: %s", result.str().c_str());

    // Prepare to return the output
    std::string output = result.str();
    std::string response;

    // Check if "radio" is in the output

    // Return the combined result to display in the EditText
    return env->NewStringUTF(output.c_str());
}


extern "C"
JNIEXPORT jstring JNICALL
Java_com_root_jnidetection_MainActivity_checkSbin(JNIEnv *env, jobject obj) {
    // Command to execute 'ls -la /sbin'
    const char* command = "ls";

    // Buffer to hold the output
    char buffer[128];
    std::stringstream result;

    // Open the process using popen (process open)
    FILE* pipe = popen(command, "r");
    if (!pipe) {
        LOGE("Failed to run command: %s", command);
        return env->NewStringUTF("Error running command");
    }

    // Read the output of the command
    while (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        result << buffer;
    }

    // Close the process
    pclose(pipe);

    // Log the result for debugging
    LOGI("Command output: %s", result.str().c_str());

    // Prepare the output to return
    std::string output = result.str();

    if (output.empty()) {
        // If the output is empty, return a "No output" message
        return env->NewStringUTF("No output from ls -la /sbin command.");
    } else {
        // Return the output of the ls command
        return env->NewStringUTF(output.c_str());
    }
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_root_jnidetection_MainActivity_getProcurr(JNIEnv *env, jobject obj) {
    std::ifstream mapsFile("/proc/self/attr/current");
    std::string line;
    std::string result;

    if (!mapsFile.is_open()) {
        LOGE("Could not open /proc/self/attr/currents");
        return env->NewStringUTF("Error opening /proc/self/attr/current");
    }

    // Read the maps file line by line
    while (std::getline(mapsFile, line)) {
        // Check if the line contains memfd:jit-cache
       // if (line.find("memfd:jit-cache") != std::string::npos || (line.find(".so") != std::string::npos && line.find("x") != std::string::npos))
     {
            result += line + "\n";  // Append the line containing memfd:jit-cache to the result
        }
    }

    mapsFile.close();

    // Check if any rows were found
    if (result.empty()) {
        return env->NewStringUTF("magisk not found in /proc/self/attr/current\n");
    }

    // Return the result to display in the EditText
    return env->NewStringUTF(result.c_str());
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

            "/system/sbin/magisk",
            "/system/bin/magisk",
            "/system/xbin/magisk",
            "/odm/bin/magisk",
            "/vendor/bin/magisk",
            "/vendor/bin/magisk",
            "/vendor/xbin/magisk",
            "/debug_ramdisk/magisk",
            "/debug_ramdisk/su",
            "/sbin/magisk",
            ".magisk/rootdir",
//            "/system/bin/su",
//            "/system/xbin/su",
//            "/data/local/xbin/su",
//            "/data/local/bin/su",
            "/sbin/su",
            "/su/bin/su",
            "/odm/bin/su",
            "/vendor/bin/su",
            "/vendor/xbin/su",
//            "/vendor/bin/su",
//            "/data/local/",
//            "/data/local/bin/",
//            "/data/local/xbin/",
//            "/sbin/",
            "/su/bin/",
            "/system/bin/su",
            "/system/xbin/su",
//            "/system/bin/.ext/",
//            "/system/bin/failsafe/",
//            "/system/sd/xbin/",
            "/system/usr/we-need-root/",
//            "/system/xbin/",
//            "/cache/",
//            "/dev/",
//            "/system",
//            "/system/bin",
//            "/system/sbin",
//            "/system/xbin",
//            "/vendor/bin",
            "/system/sbin/magisk",
            "/system/bin/magisk",
            "/system/xbin/magisk",
            "/odm/bin/magisk",
            "/vendor/bin/magisk",
            "/vendor/xbin/magisk",
            "/debug_ramdisk/magisk",
            "/debug_ramdisk/su",
            "/sbin/magisk",
            ".magisk/rootdir",
            "/sbin/su",
            "/su/bin/su",
            "/odm/bin/su",
            "/vendor/bin/su",
            "/vendor/xbin/su",
            "/su/bin/",
            "/system/bin/su",
            "/system/xbin/su",
            "/system/usr/we-need-root/",
            "/system/sd/xbin/",
            "/system/bin/failsafe/",
            "/system/bin/",
            "/system/xbin/",
            "/system/etc/",
            "/system/bin/.ext/",
            "/system/xbin/supolicy",
            "/system/xbin/su",
            "/system/xbin/ku.sud",
            "/system/usr/iku/isu",
            "/system/bin/am",
            "/system/xbin/daemonsu",
            "/system/xbin/sugote",
            "/system/bin/.ext/.su",
            "/system/su.d/",
            "/system/su.d/$i",
            "/system/xbin/sugote-mksh",
            "/system/bin/%s",
            "/system/bin/toolbox",
            "/system/xbin/sush",
            "/system/framework",
            "/system/lib",
            "/system/vendor/sns/sensors/registry/",
            "/system/vendor/sns/sensors/registry/registry/",
            "/system/vendor/mpt/",
            "/system/vendor/vzw/",
            "/dev/.su.d",
            "/dev/.su.d.complete",
            "/dev/socket/su-daemon/",
            "/dev/urandom",
            "/dev/random"
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
}extern "C"
JNIEXPORT jstring JNICALL
Java_com_root_jnidetection_MainActivity_detectMagiskServices(JNIEnv *env, jobject obj) {
    const prop_info* prop;
    char name[PROP_NAME_MAX];
    char value[PROP_VALUE_MAX];
    int i = 0;
    std::stringstream result;

    while ((prop = __system_property_find_nth(i)) != NULL) {
        __system_property_read(prop, name, value);

        // Check if the property starts with "init.svc."
        if (strncmp(name, "init.svc.", 9) == 0) {
            const char* service_name = name + 9;  // Service name after "init.svc."
            int len = strlen(service_name);

            // Check if the remaining string is 7 characters and alphanumeric
            if (len == 7 && isalnum(service_name[0])) {
                int valid = 1;
                for (int j = 1; j < 7; ++j) {
                    if (!isalnum(service_name[j])) {
                        valid = 0;
                        break;
                    }
                }

                // Check if service state is "stopped"
                if (valid && strcmp(value, "stopped") == 0) {
                    result << "Potential Magisk service detected: " << service_name
                           << " (state: " << value << ")\n";
                }
            }
        }

        i++;
    }

    // If no services are detected
    if (result.str().empty()) {
        result << "No potential Magisk services detected.";
    }

    // Return the result to be displayed in the EditText
    return env->NewStringUTF(result.str().c_str());
}
extern "C"
JNIEXPORT jstring JNICALL
Java_com_root_jnidetection_MainActivity_getProcSelfFd(JNIEnv *env, jobject /* this */) {
    std::string result;
    const char* fdPath = "/proc/self/fd";

    // Open the directory
    DIR* dir = opendir(fdPath);
    if (!dir) {
        LOGE("Failed to open /proc/self/fd");
        return env->NewStringUTF("Error opening /proc/self/fd");
    }

    struct dirent* entry;
    char linkTarget[PATH_MAX];
    char fileBuffer[1024];  // Buffer to read file content

    // Read each entry (file descriptor) in /proc/self/fd
    while ((entry = readdir(dir)) != nullptr) {
        if (entry->d_type == DT_LNK) {  // Check if it is a symbolic link
            std::string fdFile = std::string(fdPath) + "/" + entry->d_name;

            // Read the symbolic link
            ssize_t len = readlink(fdFile.c_str(), linkTarget, sizeof(linkTarget) - 1);
            if (len != -1) {
                linkTarget[len] = '\0';  // Null-terminate the string
                result += std::string("FD ") + entry->d_name + ": " + linkTarget + "\n";

                // Attempt to open the file descriptor and read its contents
                int fd = open(fdFile.c_str(), O_RDONLY);
                if (fd != -1) {
                    ssize_t bytesRead = read(fd, fileBuffer, sizeof(fileBuffer) - 1);
                    if (bytesRead > 0) {
                        fileBuffer[bytesRead] = '\0';  // Null-terminate the content
                        result += "Content:\n" + std::string(fileBuffer) + "\n";
                    } else {
                        result += "Could not read content from FD " + std::string(entry->d_name) + "\n";
                    }
                    close(fd);
                } else {
                    result += "Failed to open FD " + std::string(entry->d_name) + "\n";
                }
            }
        }
    }

    closedir(dir);

    // Return the result back to Java
    if (result.empty()) {
        return env->NewStringUTF("No valid file descriptors found in /proc/self/fd");
    }
    return env->NewStringUTF(result.c_str());
}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_root_jnidetection_MainActivity_checkLibcExists(JNIEnv *env, jobject /* this */) {
    const char *path = "/apex/com.android.runtime/lib64/bionic/libart.so";
    std::ifstream file(path);

    if (file.good()) {
        LOGI("Found libart.so at %s", path);
        return env->NewStringUTF("Found libc.so at /apex/com.android.runtime/lib64/bionic/libart.so");
    } else {
        LOGE("libart.so not found at %s", path);
        return env->NewStringUTF("libart.so not found");
    }
}