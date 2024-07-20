#include "library/itunes/itunestrackmodel.h"

#include "library/baseexternaltrackmodel.h"
#include "library/basetrackcache.h"
#ifdef __IOS_ITUNES_LIBRARY__
#include "library/itunes/itunesiosassetexporter.h"
#endif
#include <QObject>
#include <QSharedPointer>
#include <QStandardPaths>
#include <QString>

#include "library/trackcollectionmanager.h"
#include "moc_itunestrackmodel.cpp"

ITunesTrackModel::ITunesTrackModel(QObject* parent,
        TrackCollectionManager* pTrackCollectionManager,
        QSharedPointer<BaseTrackCache> trackSource)
        : BaseExternalTrackModel(parent,
                  pTrackCollectionManager,
                  "mixxx.db.model.itunes",
                  "itunes_library",
                  trackSource) {
}

QString ITunesTrackModel::resolveLocation(const QString& nativeLocation) const {
#ifdef __IOS_ITUNES_LIBRARY__
    if (nativeLocation.startsWith("ipod-library:")) {
        QString musicDir = QStandardPaths::writableLocation(QStandardPaths::MusicLocation);
        ITunesIOSAssetExporter exporter(QDir(musicDir + "/Mixxx/iTunes Tracks"));
        return exporter.exportAsset(QUrl(nativeLocation));
    }
#endif
    return BaseExternalTrackModel::resolveLocation(nativeLocation);
}
