package com.renren.mobile.android.recorder;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

public class RecorderActivity extends Activity {

    private Button mBtnStartRecord;
    private Button mBtnStopRecord;
    private RecorderView mRecorderView;



    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        initViews();
    }

    private void initViews(){
        setContentView(R.layout.activity_recorder);
        mBtnStartRecord = (Button)findViewById(R.id.recorder_btn_start_record);
        mBtnStopRecord = (Button)findViewById(R.id.recorder_btn_stop_record);
        mRecorderView = (RecorderView)findViewById(R.id.recorder_surface);

        mBtnStartRecord.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mRecorderView.startRecord();
            }
        });

        mBtnStopRecord.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                mRecorderView.stopRecord();
            }
        });

    }
}
