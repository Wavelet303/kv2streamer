/*
 * Copyright (c) 2014 Samsung Electronics Corporation.
 * 
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 * 
 *    http://www.apache.org/licenses/LICENSE-2.0
 * 
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "AbstractMulticaster.h"
#include <gst-wrapper/GstAppSrcPipeline.h>

#define SUBFRAME_LENGTH 1024

class AudioMulticaster : public AbstractMulticaster
{
public:
	AudioMulticaster(std::string multicastIP, int port);
	~AudioMulticaster(void);

	virtual HRESULT InitializeMulticasterAndSubscribeHandle(IKinectSensor* kinectSensor, WAITABLE_HANDLE &waitableHandle);
	virtual void ProcessNewFrame(WAITABLE_HANDLE &waitableHandle);

private:

	IAudioBeamFrameReader*	audioBeamFrameReader;
	kv2s::GstAppSrcPipeline	gstSender;
	UINT					subframeLength;
	BYTE*					audioSubFrameBuffer;
	void					ProcessNewAudioSubFrame(IAudioBeamSubFrame* subFrame);
};

