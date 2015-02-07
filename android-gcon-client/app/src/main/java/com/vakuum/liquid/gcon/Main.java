package com.vakuum.liquid.gcon;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.SeekBar;
import android.widget.Spinner;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;
import java.util.ArrayList;
import java.util.List;


public class Main extends Activity {

    public static final String SERVER_IP_1 = "192.168.0.44";
    public static final String SERVER_IP_2 = "192.168.0.50";
    public static final int SERVER_PORT = 7727;
    private Spinner hostSpinner;
    private Socket socket;
    private static boolean inhibitStatus = false;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        new Thread(new ClientThread()).start();


        final Button muteBtn = (Button) findViewById(R.id.mute_btn);
        muteBtn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                Log.w("cmd", "mute");
                JSONObject obj = new JSONObject();
                try {
                    obj.put("cmd", "mute");
                } catch (JSONException e) {
                    e.printStackTrace();
                }
                sendCommand(obj);
            }
        });

        final SeekBar sBar = (SeekBar) findViewById(R.id.seekBar);
        sBar.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            int progressChanged = 0;

            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser){
                progressChanged = progress;
            }

            public void onStartTrackingTouch(SeekBar seekBar) {
                // TODO Auto-generated method stub
            }

            public void onStopTrackingTouch(SeekBar seekBar) {
                Log.w("cmd", "volume");
                JSONObject obj = new JSONObject();
                try {
                    obj.put("cmd", "volume");
                    obj.put("volume", progressChanged);
                } catch (JSONException e) {
                    e.printStackTrace();
                }
                sendCommand(obj);
            }
        });

        final Button suspBtn = (Button) findViewById(R.id.susp_btn);
        suspBtn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                Log.w("cmd", "suspend");
                JSONObject obj = new JSONObject();
                try {
                    obj.put("cmd", "suspend");
                } catch (JSONException e) {
                    e.printStackTrace();
                }
                sendCommand(obj);
            }
        });

        final Button unlockBtn = (Button) findViewById(R.id.unlock_btn);
        unlockBtn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                Log.w("cmd", "inhibit");
                inhibitStatus = !inhibitStatus;
                JSONObject obj = new JSONObject();
                try {
                    obj.put("cmd", "inhibit");
                    obj.put("inhibit", inhibitStatus);
                } catch (JSONException e) {
                    e.printStackTrace();
                }
                sendCommand(obj);
                if (inhibitStatus) {
                    unlockBtn.setText("Unlock ScreenSaver");
                } else {
                    unlockBtn.setText("Lock ScreenSaver");
                }
            }
        });

        hostSpinner = (Spinner) findViewById(R.id.spinner);
        List<String> list = new ArrayList<String>();
        list.add(SERVER_IP_2);
        list.add(SERVER_IP_1);
        ArrayAdapter<String> dataAdapter = new ArrayAdapter<String>(this,
                android.R.layout.simple_spinner_item, list);
        dataAdapter.setDropDownViewResource(android.R.layout.simple_spinner_dropdown_item);
        hostSpinner.setAdapter(dataAdapter);
    }


    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);
        return true;
    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.
        int id = item.getItemId();
        if (id == R.id.action_settings) {
            return true;
        }
        return super.onOptionsItemSelected(item);
    }

    private void sendCommand(JSONObject jsonCmd) {
        new Thread(new ClientThread()).start();

        try {
            BufferedOutputStream bos = new BufferedOutputStream(socket.getOutputStream());
            bos.write(jsonCmd.toString().getBytes()); // writes to the buffer
            bos.flush() ;
        } catch (IOException e1) {
            e1.printStackTrace();
        }
    }

    class ClientThread implements Runnable {
        public void run() {
            try {
                InetAddress serverAddr = InetAddress.getByName(hostSpinner.getSelectedItem().toString());
                socket = new Socket(serverAddr, SERVER_PORT);
            } catch (UnknownHostException e1) {
                e1.printStackTrace();
            } catch (IOException e1) {
                e1.printStackTrace();
            }
        }
    }

}
