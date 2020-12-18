#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMediaPlayer>
#include <QMediaPlaylist>
#include <QString>
#include <QStringList>
#include <QTime>



QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

signals:
    void numMusic(int);
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QString LastAddPath;



    //播放音乐的变量
    QMediaPlayer *Player;

    bool isPlaying;

    //当前音乐播放的列表
    QMediaPlaylist *PlayerList;


    //当前音乐播放的列表名字
    QStringList *NameList ;



    //当前音乐的时长
    qint64 Time;
    //当前播放到的位置
    QTime *nowTime;
    //播放方式，随机播放，顺序播放，循环播放
    int playWay;

    //当前音量的大小
    int volum;

    //改变播放方式
    void changePlayWay();

    //添加歌曲队列
    void addMusicList();
    //添加电脑上音乐到本地音乐
    void addMusicToLocal();

    //开始播放当前音乐
    void startPlayingMusic();

    //停止播放当前音乐
    void stopPlayingMusic();

    //暂停播放当前音乐
    void pausePlayingMusic();

    //音量+，音量-
    void addVolum();
    void releaseVolum();
    void changeVolum(int volum);

    //上下首
    void nextMusic();
    void lastMusic();

    //初始化检查
    bool initialCheck();

    void musicControlSlider();
    void sliderControlMusic();


    //点击播放列表看是播放哪一首歌
    void playWhichMusic(int);

    void changePlayList();

    void changeWidgeSize(int w, int h);

    enum{AddVOLUM,ReleaseVOLUM,NEXTSong,LASTSong,ONELOOPPLAY,ALLLOOPPLAY,RANGDOMPLAY,ALLPLAY};
    enum{VOLUM=0,SLIDER};
};

#define PATH QString("./data/")
#define PATH_INFO QString("INFO.lmz")
#define PATH_LIST1 QString("LIST1.lmz")
#define PATH_LIST2 QString("LIST2.lmz")
#define PATH_LIST3 QString("LIST3.lmz")
#define PATH_SETTING QString("SETTING.lmz")

#endif // MAINWINDOW_H
