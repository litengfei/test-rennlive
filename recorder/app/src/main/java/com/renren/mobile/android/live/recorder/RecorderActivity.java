package com.renren.mobile.android.live.recorder;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import com.renren.library.live.RennLiveJni;
import com.renren.mobile.android.live.R;

public class RecorderActivity extends Activity {

    private Button mBtnStartRecord;
    private Button mBtnStopRecord;
    private Button mBtnTest;
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
        mBtnTest = (Button)findViewById(R.id.recorder_btn_test);
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


        mBtnTest.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                RennLiveJni.test();
            }
        });
    }
}
