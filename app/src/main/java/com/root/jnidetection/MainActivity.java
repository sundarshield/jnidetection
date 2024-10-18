//package com.root.jnidetection;
//import android.Manifest;
//import android.content.pm.PackageManager;
//import android.os.Bundle;
//import android.util.Log;
//
//import android.widget.EditText;
//import android.widget.Toast;
//import androidx.appcompat.app.AppCompatActivity;
//import androidx.core.app.ActivityCompat;
//import androidx.core.content.ContextCompat;
//
//public class MainActivity extends AppCompatActivity {
//
//    private static final int PERMISSION_REQUEST_CODE = 100;
//    private static final int REQUEST_WRITE_STORAGE = 112;
//
//    static {
//        System.loadLibrary("jnidetection");
//    }
//
//    // Declare the native methods
//    public native String getProcSelfMaps();
//    public native String getDex2OatFlags();
//    public native String checkSuBinary();
//    //public native String checkLibcExists();
//public native String checkMagisk();
//    public native String getProcSelfFd();
//    public native String getProcurr();
//
//    public native String checkDevBlock();
//
//
//
//    private EditText editText;
//
//    @Override
//    protected void onCreate(Bundle savedInstanceState) {
//        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_main);
//
//        editText = findViewById(R.id.editTextProcMaps);
//                   executeNativeMethods();
////        // Check and request permissions
////        if (checkPermission()) {
////            executeNativeMethods();  // Call native methods if permission granted
////        } else {
////            requestPermission();
////        }
//    }
//
//    private void executeNativeMethods() {
//       // String result = checkLibcExists();
//        String res= getProcSelfFd();
//        editText.setText(checkDevBlock());
//        Log.d("JNI_RESULT", "Result from JNI: " + checkDevBlock());
//        editText.append(getProcurr()+"\n");
//        editText.append(checkMagisk());
//        editText.append(res + "/proc/self/fd\n\n...");
//    //    editText.append(result + "\n\n...");
//
//        String suCheckResult = checkSuBinary();
//        editText.append(suCheckResult);
//
//        String dex2OatFlags = getDex2OatFlags();
//        editText.append("\nDalvik VM dex2oat-flags:\n" + dex2OatFlags);
//
//        String mapsResult = getProcSelfMaps();
//        editText.append(mapsResult);
//    }
//
////    private boolean checkPermission() {
////        int writePermission = ContextCompat.checkSelfPermission(this, Manifest.permission.WRITE_EXTERNAL_STORAGE);
////        int readPermission = ContextCompat.checkSelfPermission(this, Manifest.permission.READ_EXTERNAL_STORAGE);
////        return writePermission == PackageManager.PERMISSION_GRANTED && readPermission == PackageManager.PERMISSION_GRANTED;
////    }
////
////
////    private void requestPermission() {
////        if (ActivityCompat.shouldShowRequestPermissionRationale(this, Manifest.permission.WRITE_EXTERNAL_STORAGE) ||
////                ActivityCompat.shouldShowRequestPermissionRationale(this, Manifest.permission.READ_EXTERNAL_STORAGE)) {
////            Toast.makeText(this, "Storage permission is required to save files", Toast.LENGTH_LONG).show();
////        }
////        ActivityCompat.requestPermissions(this, new String[]{
////                Manifest.permission.WRITE_EXTERNAL_STORAGE,
////                Manifest.permission.READ_EXTERNAL_STORAGE
////        }, PERMISSION_REQUEST_CODE);
////    }
//
// //   @Override
////    public void onRequestPermissionsResult(int requestCode, String[] permissions, int[] grantResults) {
////        super.onRequestPermissionsResult(requestCode, permissions, grantResults);
////        if (requestCode == PERMISSION_REQUEST_CODE) {
////            if (grantResults.length > 0 && grantResults[0] == PackageManager.PERMISSION_GRANTED) {
////                Toast.makeText(this, "Permission granted", Toast.LENGTH_SHORT).show();
////                executeNativeMethods();
////            } else {
////                Toast.makeText(this, "Permission denied", Toast.LENGTH_SHORT).show();
////            }
////        }
////    }
//}


package com.root.jnidetection;

import android.content.pm.ApplicationInfo;
import android.content.pm.PackageInfo;
import android.content.pm.PackageManager;
import android.content.pm.PackageStats;
import android.content.pm.Signature;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.widget.EditText;

import androidx.appcompat.app.AppCompatActivity;

import java.io.File;
import java.util.List;
import android.os.AsyncTask;
import android.os.Bundle;
import android.util.Log;
import android.widget.EditText;
import android.widget.Toast;

import androidx.appcompat.app.AppCompatActivity;
//
//public class MainActivity extends AppCompatActivity {
//
//    static {
//        System.loadLibrary("jnidetection");
//    }
//
//    // Declare the native methods
//    public native String getProcSelfMaps();
//    public native String getDex2OatFlags();
//    public native String checkSuBinary();
//    public native String checkMagisk();
//    public native String getProcSelfFd();
//    public native String getProcurr();
//    public native String checkDevBlock();
//
//    private EditText editText;
//
//    @Override
//    protected void onCreate(Bundle savedInstanceState) {
//        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_main);
//
//        editText = findViewById(R.id.editTextProcMaps);
//
//        // Execute native methods asynchronously to avoid UI hang
//        new ExecuteNativeMethodsTask().execute();
//    }
//
//    private class ExecuteNativeMethodsTask extends AsyncTask<Void, String, String[]> {
//        @Override
//        protected String[] doInBackground(Void... voids) {
//            String[] results = new String[6];
//
//            // Execute JNI methods
//            results[0] = checkDevBlock();
//            results[1] = getProcurr();
//            results[2] = checkMagisk();
//            results[3] = getProcSelfFd();
//            results[4] = checkSuBinary();
//            results[5] = getDex2OatFlags();
//
//            return results;
//        }
//
//        @Override
//        protected void onPostExecute(String[] results) {
//            // Update the UI with results
//            editText.setText(results[0]); // Display the output of checkDevBlock
//            Log.d("JNI_RESULT", "Result from JNI: " + results[0]);
//            editText.append("\n" + results[1] + "\n"); // Display getProcurr
//            editText.append(results[2] + "\n"); // Display checkMagisk
//            editText.append(results[3] + "/proc/self/fd\n\n..."); // Display getProcSelfFd
//            editText.append(results[4]); // Display checkSuBinary
//            editText.append("\nDalvik VM dex2oat-flags:\n" + results[5]); // Display dex2OatFlags
//        }
//    }
//}

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("jnidetection"); // Ensure the library is loaded
    }

    private EditText resultEditText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        resultEditText = findViewById(R.id.editTextProcMaps); // Your EditText ID
      //  getPackageSignature("xxn.nxqgxrx");
        // Call the JNI method
        String result = getProcSelfMaps();
        String result1=checkDevBlock();
        String result2=checkSEpolocy();

        resultEditText.setText(detectMagiskServices()+"\n\n");
        resultEditText.append(checkMounts()+"\n\n");
        resultEditText.append((getPackageInfo("qhh.eulhehkemse.cd"))+"\n\n");
        resultEditText.append(checkSuBinary()+"\n\n");
        resultEditText.append(getFilteredPackages()+"\n\n");

        resultEditText.append(getProcurr()+"\n\n");
        resultEditText.append(checkMountInfo()+"\n\n");
        resultEditText.append(result2+"\n\n\n\n");
        resultEditText.append(result1);


     //   resultEditText.append(result);

    }

    // Declare the native method
        public native String getProcSelfMaps();
    public native String getDex2OatFlags();
    public native String checkSuBinary();
    public native String checkMagisk();
    public native String getProcSelfFd();
    public native String getProcurr();
    public native String checkDevBlock();
public native String checkMountInfo();
    public  native String checkSEpolocy();
public  native String checkMounts();

public native String listInstalledPackages();
    public native String checkSbin();

    public native String getFilteredPackages();
public  native String detectMagiskServices();


    private String getPackageInfo(String packageName) {
        PackageManager packageManager = getPackageManager();
        StringBuilder infoString = new StringBuilder();

        try {
            PackageInfo packageInfo = packageManager.getPackageInfo(packageName, PackageManager.GET_SIGNATURES);
            ApplicationInfo applicationInfo = packageInfo.applicationInfo;

            // Get package signatures
            Signature[] signatures = packageInfo.signatures;
            infoString.append("Signatures:\n");
            for (Signature signature : signatures) {
                infoString.append(signature.toCharsString()).append("\n");
            }
            infoString.append("Version Name: ").append(packageInfo.versionName).append("\n");
            infoString.append("Version Code: ").append(packageInfo.versionCode).append("\n");

            // Get package icon path (APK path)
//            String iconPath = applicationInfo.sourceDir; // This will give you the APK path
//            infoString.append("Icon Path: ").append(iconPath).append("\n");
//
//            // Get cache size (not directly available, this is a placeholder)
//            long cacheSize = getCacheSize(packageName);
//            infoString.append("Cache Size: ").append(cacheSize).append(" bytes\n");
//
//            // Get memory info (not directly available for each package, placeholder)
//            long memoryUsage = getMemoryUsage(packageName);
//            infoString.append("Memory Usage: ").append(memoryUsage).append(" bytes\n");

        } catch (PackageManager.NameNotFoundException e) {
            Toast.makeText(this, "Package not found: " + packageName, Toast.LENGTH_SHORT).show();
            return "Package not found: " + packageName;
        } catch (Exception e) {
            Toast.makeText(this, "Error retrieving package info: " + e.getMessage(), Toast.LENGTH_SHORT).show();
            return "Error retrieving package info: " + e.getMessage();
        }

        return infoString.toString(); // Return the collected info as a String
    }

    private long getCacheSize(String packageName) {
        // Placeholder for cache size calculation
        return 0; // Return 0 as a placeholder
    }

    private long getMemoryUsage(String packageName) {
        // Placeholder for memory usage calculation
        return 0; // Return 0 as a placeholder
    }
}
