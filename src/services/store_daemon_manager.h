/*
 * Copyright (C) 2018 Deepin Technology Co., Ltd.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef DEEPIN_APPSTORE_SERVICES_STORE_DAEMON_MANAGER_H
#define DEEPIN_APPSTORE_SERVICES_STORE_DAEMON_MANAGER_H

#include <QObject>

#include "services/search_result.h"

namespace dstore {

class StoreDaemonManager : public QObject {
  Q_OBJECT
 public:
  explicit StoreDaemonManager(QObject* parent = nullptr);
  ~StoreDaemonManager() override;

 signals:
  void isDbusConnectedRequest();

  void cleanArchivesRequest();
  void cleanJobRequest(const QString& job);
  void pauseJobRequest(const QString& job);
  void startJobRequest(const QString& job);
  void installPackageRequest(const QString& app_name);
  void packageExistsRequest(const QString& app_name);
  void packageInstallableRequest(const QString& app_name);
  void packageDownloadSizeRequest(const QString& app_name);
  void updatePackageRequest(const QString& app_name);
  void removePackageRequest(const QString& app_name);
  void upgradableAppsRequest();

  void applicationUpdateInfosRequest(const QString& language);

  void jobListRequest();
  void getJobInfoRequest(const QString& job);

  void openAppRequest(const QString& app_name);


  void isDbusConnectedReply(bool state);

  void cleanArchivesReply(const QVariantMap& result);
  void cleanJobReply(const QVariantMap& result);
  void pauseJobReply(const QVariantMap& result);
  void startJobReply(const QVariantMap& result);
  void installPackageReply(const QVariantMap& result);
  void packageExistsReply(const QVariantMap& result);
  void packageInstallableReply(const QVariantMap& result);
  void packageDownloadSizeReply(const QVariantMap& result);
  void updatePackageReply(const QVariantMap& result);
  void removePackageReply(const QVariantMap& result);
  void jobListReply(const QVariantMap& result);
  void upgradableAppsReply(const QVariantMap& result);

  void applicationUpdateInfosReply(const QVariantMap& result);
  void getJobInfoReply(const QVariantMap& result);

 public slots:
  void updateAppList(const AppSearchRecordList& app_list);

 private:
  AppSearchRecordMap apps_;
};

}  // namespace dstore

#endif  // DEEPIN_APPSTORE_SERVICES_STORE_DAEMON_MANAGER_H
