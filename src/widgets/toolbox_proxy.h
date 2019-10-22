/* 
 * (c) 2017, Deepin Technology Co., Ltd. <support@deepin.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * is provided AS IS, WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, and
 * NON-INFRINGEMENT.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
#ifndef _DMR_TOOLBOX_PROXY_H
#define _DMR_TOOLBOX_PROXY_H 

#include <DPlatformWindowHandle>
//#include <QtWidgets>
#include <DWidget>
#include <QFrame>
#include <QHBoxLayout>
#include <QTimer>
#include <DIconButton>
#include <DButtonBox>
#include <DBlurEffectWidget>

namespace Dtk
{
namespace Widget
{
    class DImageButton;
}
}

DWIDGET_USE_NAMESPACE

namespace dmr {
class PlayerEngine;
class VolumeButton;
class MainWindow;
class DMRSlider;
class ThumbnailPreview;
class SubtitlesView;
class VolumeSlider;
class ViewProgBar;
class viewProgBarLoad;

class ToolboxProxy: public QFrame {
    Q_OBJECT
public:
    ToolboxProxy(QWidget *mainWindow, PlayerEngine*);
    virtual ~ToolboxProxy();

    void updateTimeInfo(qint64 duration, qint64 pos);
    bool anyPopupShown() const;
    void closeAnyPopup();

signals:
    void requestPlay();
    void requestPause();
    void requestNextInList();
    void requesstPrevInList();

protected slots:
    void updatePosition(const QPoint& p);
    void buttonClicked(QString id);
    void updatePlayState();
    void updateFullState();
    void updateVolumeState();
    void updateMovieProgress();
    void updateButtonStates();
    void setProgress(int v);
    void progressHoverChanged(int v);
    void updateHoverPreview(const QUrl& url, int secs);
    void setViewProgBar();

protected:
    void paintEvent(QPaintEvent *pe) override;
    void showEvent(QShowEvent *event) override;
    void resizeEvent(QResizeEvent *event) override;

private:
    void setup();
    void updateTimeLabel();

    MainWindow *_mainWindow {nullptr};
    PlayerEngine *_engine {nullptr};
    QLabel *_timeLabel {nullptr};
    QLabel *_timeLabelend {nullptr};
    VolumeSlider *_volSlider {nullptr};

//    DImageButton *_playBtn {nullptr};
//    DIconButton *_playBtn {nullptr};
//    DIconButton *_prevBtn {nullptr};
//    DIconButton *_nextBtn {nullptr};

    DButtonBoxButton *_playBtn {nullptr};
    DButtonBoxButton *_prevBtn {nullptr};
    DButtonBoxButton *_nextBtn {nullptr};
    DButtonBox *_palyBox{nullptr};

    DIconButton *_subBtn {nullptr};
    VolumeButton *_volBtn {nullptr};
    DIconButton *_listBtn {nullptr};
    DIconButton *_fsBtn {nullptr};

    QHBoxLayout *_mid{nullptr};
    QHBoxLayout *_right{nullptr};
    ViewProgBar *_viewProgBar{nullptr};

    DMRSlider *_progBar {nullptr};
    DWidget *_progBarspec {nullptr};
    ThumbnailPreview *_previewer {nullptr};
    SubtitlesView *_subView {nullptr};
    int _lastHoverValue {0};
    QTimer _previewTimer;
};
}

//HACK: extent area for progress slider
#define TOOLBOX_TOP_EXTENT  0
#define TOOLBOX_HEIGHT  70
#define TOOLBOX_HEIGHT_EXT (TOOLBOX_HEIGHT + TOOLBOX_TOP_EXTENT)

#endif /* ifndef _DMR_TOOLBOX_PROXY_H */
