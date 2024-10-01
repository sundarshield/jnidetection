package com.root.jnidetection;
//
//
//import androidx.appcompat.app.AppCompatActivity;
//import android.os.Bundle;
//import android.widget.EditText;
//
//public class MainActivity extends AppCompatActivity {
//
//    private EditText editTextInitSvcStatus;
//
//    @Override
//    protected void onCreate(Bundle savedInstanceState) {
//        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_main);
//
//        // Initialize the EditText
//        editTextInitSvcStatus = findViewById(R.id.editTextInitSvcStatus);
//
//        // Call the native method to get /proc/self/maps
//        String mapsResult = getProcSelfMaps();
//
//        // Display the result in EditText
//        editTextInitSvcStatus.setText(mapsResult);
//    }
//
//    // Declare the native method
//    public native String getProcSelfMaps();
//
//    // Load the native library
//    static {
//        System.loadLibrary("jnidetection");
//    }
//}




//package com.root.jnidetection;

import android.os.Bundle;
import android.widget.EditText;
import android.widget.Toast;
import androidx.appcompat.app.AppCompatActivity;

//public class MainActivity extends AppCompatActivity {
//
//    static {
//        System.loadLibrary("jnidetection");
//    }
//
//    // Declare the native method that returns /proc/self/maps and saves to a file
//    public native String getProcSelfMaps(String filePath);
//    public native String getDex2OatFlags();
//
//    private EditText editTextProcMaps;
//
//    @Override
//    protected void onCreate(Bundle savedInstanceState) {
//        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_main);
//
//        editTextProcMaps = findViewById(R.id.editTextProcMaps);
//
//        String dex2oatFlags = getDex2OatFlags();
//        editTextProcMaps.setText(dex2oatFlags);
//
//        // Define the file path where /proc/self/maps will be saved
//
////        String filePath = getFilesDir() + "/maps.txt";
////        String mapsContent = getProcSelfMaps(filePath);
////        editTextProcMaps.setText(mapsContent);
//
//       // Toast.makeText(this, "Saved to: " + filePath, Toast.LENGTH_LONG).show();
//    }
//}





public class MainActivity extends AppCompatActivity {

    // Load the JNI library
    static {
        System.loadLibrary("jnidetection");
    }

    // Declare the native methods
    public native String getProcSelfMaps();
    public native String getDex2OatFlags();

    public native String checkSuBinary();

    private EditText editText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);


        // Find the EditText in the layout
        editText = findViewById(R.id.editTextProcMaps);

        String suCheckResult = checkSuBinary();
        editText.setText(suCheckResult);  // Display the result in EditText

        // Get the result of /proc/self/maps and append to the EditText
        String dex2OatFlags = getDex2OatFlags();
        editText.append("\nDalvik VM dex2oat-flags:\n\n\n\n" + dex2OatFlags);

        String mapsResult = getProcSelfMaps();
        editText.append(mapsResult);

        // Get the dex2oat flags and append to the EditText

    }
}