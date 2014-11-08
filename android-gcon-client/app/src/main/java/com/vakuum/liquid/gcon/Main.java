package com.vakuum.liquid.gcon;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.Button;
import android.widget.SeekBar;

import org.json.JSONException;
import org.json.JSONObject;

import java.io.BufferedOutputStream;
import java.io.DataOutputStream;
import java.io.IOException;
import java.net.InetAddress;
import java.net.Socket;
import java.net.UnknownHostException;


public class Main extends Activity {

    public static final String SERVER_IP = "192.168.0.44";
    public static final int SERVER_PORT = 7727;
    private Socket socket;

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

        final Button volBtn = (Button) findViewById(R.id.vol_btn);
        volBtn.setOnClickListener(new View.OnClickListener() {
            public void onClick(View v) {
                Log.w("cmd", "volume");
                JSONObject obj = new JSONObject();
                try {
                    obj.put("cmd", "volume");
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
                InetAddress serverAddr = InetAddress.getByName(SERVER_IP);
                socket = new Socket(serverAddr, SERVER_PORT);
            } catch (UnknownHostException e1) {
                e1.printStackTrace();
            } catch (IOException e1) {
                e1.printStackTrace();
            }
        }
    }

}
