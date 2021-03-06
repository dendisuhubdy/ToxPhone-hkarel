#pragma once

#include "shared/list.h"
#include "shared/clife_alloc.h"
#include "shared/clife_base.h"
#include "shared/clife_ptr.h"
#include "shared/container_ptr.h"
#include "shared/ring_buffer.h"
#include <QtCore>

/**
  Содержит базовые параметры воспроизведения/записи
*/
struct VoiceFrameInfo
{
    typedef container_ptr<VoiceFrameInfo> Ptr;

    VoiceFrameInfo() = default;
    VoiceFrameInfo(const VoiceFrameInfo&) = default;
    VoiceFrameInfo(quint32 latency,
                   quint8  channels,
                   quint32 sampleSize,
                   quint32 sampleCount,
                   quint32 samplingRate,
                   quint32 bufferSize);

    const quint32 latency      = {0}; // Интервал воспроизведения (в микросекундах)
    const quint8  channels     = {0}; // Количество каналов
    const quint32 sampleSize   = {0}; // Размер семпла
    const quint32 sampleCount  = {0}; // Количество сэмплов (зависит от latency и samplingRate)
    const quint32 samplingRate = {0}; // Частота дескретизации
    const quint32 bufferSize   = {0}; // Размер буфера данных (зависит от sampleCount,
                                      // channels и от sampleSize)
};

VoiceFrameInfo::Ptr getRecordFrameInfo(const VoiceFrameInfo* = 0, bool reset = false);
RingBuffer& recordRBuff_1();
RingBuffer& recordRBuff_2();

VoiceFrameInfo::Ptr getVoiceFrameInfo(const VoiceFrameInfo* = 0, bool reset = false);
RingBuffer& voiceRBuff();


