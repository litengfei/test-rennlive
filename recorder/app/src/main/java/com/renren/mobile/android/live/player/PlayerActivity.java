package com.renren.mobile.android.live.player;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import com.renren.mobile.android.live.R;

public class PlayerActivity extends Activity {
    private IjkVideoView mVideoView;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        initViews();
    }

    private void initViews() {
        setContentView(R.layout.activity_player);
        mVideoView = (IjkVideoView) findViewById(R.id.video_view);
        mVideoView.setVideoPath("rtmp://10.2.45.49/lzz//lzz.mp4");
        mVideoView.start();
    }
}
