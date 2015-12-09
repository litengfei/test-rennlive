package com.renren.mobile.android.recorder;

import android.content.Context;
import android.graphics.Canvas;
import android.graphics.Paint;
import android.graphics.PixelFormat;
import android.hardware.Camera;
import android.media.CamcorderProfile;
import android.media.MediaRecorder;
import android.util.AttributeSet;
import android.util.Log;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

import java.io.IOException;

/**
 * @author tengfei.li@renren-inc.com
 * @since 15/11/25, 下午7:41
 */
public class RecorderView extends SurfaceView implements SurfaceHolder.Callback, Camera.PreviewCallback {
    private static final String TAG = "mRecorder";

    private SurfaceHolder mSurfaceHolder;
    private CameraDevice mCameraDevice;
    private long mStartMillis = -1;
    private long mFramesCount = 0;

    private boolean isRecording = false;

    public RecorderView(Context context, AttributeSet attrs) {
        super(context, attrs);
        mSurfaceHolder = getHolder();
        mSurfaceHolder.setFormat(PixelFormat.TRANSPARENT);//translucent半透明 transparent透明
        mSurfaceHolder.addCallback(this);
    }

    public boolean isRecording() {
        return isRecording;
    }

    @Override
    public void surfaceCreated(SurfaceHolder holder) {
        mCameraDevice = getCamera();
        startPreview();
    }

    @Override
    public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {

    }

    @Override
    public void surfaceDestroyed(SurfaceHolder holder) {

    }

    @Override
    public void onPreviewFrame(byte[] data, Camera camera) {
        long millis = System.currentTimeMillis();
        mFramesCount++;
        if (mStartMillis < 0) {
            mStartMillis = millis;
        } else if (millis - mStartMillis > 1000) {
            Log.e(TAG, "FPS: " + mFramesCount);
            mStartMillis = millis;
            mFramesCount = 0;
        }
    }

    private static class CameraDevice {
        Camera camera;
        Camera.CameraInfo info;

        public CameraDevice(Camera camera, Camera.CameraInfo info) {
            this.camera = camera;
            this.info = info;
        }
    }

    private static CameraDevice getCamera() {
        Camera.CameraInfo info = new Camera.CameraInfo();
        int id = -1;
        int count = Camera.getNumberOfCameras();
        for (int i = 0; i < count; i++) {
            Camera.getCameraInfo(i, info);
            if (info.facing == Camera.CameraInfo.CAMERA_FACING_BACK) {
                id = i;
                break;
            }
        }
        if (id < 0) {
            if (count > 0) {
                id = 0;
                Camera.getCameraInfo(id, info);
            } else {
                return null;
            }
        }
        return new CameraDevice(Camera.open(id), info);
    }

    private void startPreview() {
        if (null != mCameraDevice) {
            try {
                Camera camera = mCameraDevice.camera;
                Camera.Parameters params = camera.getParameters();

                Log.e(TAG, "orientation:" + Integer.toString(mCameraDevice.info.orientation));

                for (int i : params.getSupportedPreviewFormats()) {
                    Log.e(TAG, "SupportedPreviewFormats:" + Integer.toString(i));
                }

                for (String s : params.getSupportedFocusModes()) {
                    Log.e(TAG, "SupportedFocusModes:" + s);
                }

                for (String s : params.getSupportedSceneModes()) {
                    Log.e(TAG, "SupportedSceneModes:" + s);
                }

                for (Camera.Size s : params.getSupportedPreviewSizes()) {
                    Log.e(TAG, "SupportedPreviewSizes:" + Integer.toString(s.height) + ":" + Integer.toString(s.width));
                }

                for (int[] r : params.getSupportedPreviewFpsRange()) {
                    String s = "";
                    for (int x : r) {
                        s += ", " + x;
                    }
                    //params.setPreviewFpsRange(6000, 30000);
                    Log.e(TAG, "SupportedPreviewFpsRange: " + s);
                }
                camera.setDisplayOrientation(mCameraDevice.info.orientation);
                camera.setPreviewDisplay(mSurfaceHolder);
                camera.setParameters(params);
                camera.startPreview();
                camera.setPreviewCallback(this);

            } catch (Exception e) {
            }
        }
    }

    private void stopPreview() {
        if (null != mCameraDevice) {
            mCameraDevice.camera.stopPreview();
        }
    }

    public void startRecord() {
    }

    public void stopRecord() {
    }

    private void releaseRecord() {
    }
}
