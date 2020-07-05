#pragma once
#ifndef RINGBUFF__HH__
#define RINGBUFF__HH__


using namespace std;

#define  MAXSIZE  1000
/*
typedef struct
{
    int iSize;//���ݵĴ�С
    char* cdata;
}bufData;
typedef struct
{
    bufData mdata[MAXSIZE];
    int iRead;//��ͷ
    int iWrite;//��β
}bufferPara;

class CycleBuffer
{
public:
    CycleBuffer(void);
    ~CycleBuffer(void);

    BOOL pushBuffer(bufferPara* Q, char* src, int strLen);//����������

    char* popBuffer(bufferPara* Q, long& dsLen);//��������

    BOOL InitQueue(bufferPara* Q);//��ʼ������
    bufferPara  mbufferPara;
    char* dest;
private:
    //bufferPara* m_RingBuffer;
    HANDLE mutexHandle;
    char* item;

};
*/
typedef struct
{
    unsigned long long timeTick;   //ʱ��(ms)
    unsigned int dataLen;     //���ݳ���
    unsigned char dataType;     //��������(DataType_E)
    unsigned char rsv[3];
    unsigned long long timeStamp;  //����ʱ���(us)
    unsigned char iFrame;    //�Ƿ�Ϊ�ؼ�֡
    unsigned char frameRate;   //֡��
    int encodeType;          //��������VideoEncodeType_E
    unsigned short width;    //��Ƶ���
    unsigned short height;    //��Ƶ�߶�
    unsigned char rsv1[8];
    unsigned char* data;
}IFVFrameHeader_S;
        


typedef struct
{
    unsigned long* m_pBuff;
    int    ifront;//��ͷ
    int    iend;//��β
    long buffSize;
}RINGBUFFER;

class CycleBuffer
{
public:
    CycleBuffer(void);
    ~CycleBuffer(void);

    bool pushBuffer(IFVFrameHeader_S* src);//����������

    IFVFrameHeader_S* popBuffer();//��������

    IFVFrameHeader_S* getBuffer();
    void pop();

    bool InitQueue();//��ʼ������
    long GetCurrDataSize();
    bool isFull();
    RINGBUFFER* m_pRingBuffer;
   //char* dest;
private:
    //bufferPara* m_RingBuffer;
   // HANDLE mutexHandle;
    //char* item;

};
#endif
