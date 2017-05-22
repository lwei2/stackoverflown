/****************************************************************************
**
** Copyright (C) 2017 Kuba Ober
**
** Permission is hereby granted, free of charge, to any person obtaining
** a copy of this software and associated documentation files (the "Software"),
** to deal in the Software without restriction, including without limitation
** the rights to use, copy, modify, merge, publish, distribute, sublicense,
** and/or sell copies of the Software, and to permit persons to whom the
** Software is furnished to do so, subject to the following conditions:
**
** The above copyright notice and this permission notice shall be included
** in all copies or substantial portions of the Software.
**
** THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
** OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
**  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
** THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
** LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
** FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
** DEALINGS IN THE SOFTWARE.
**
****************************************************************************/

#pragma once

#include "networkreplycache.h"

namespace StackOverflow {
namespace Internal {

class SOJsExtension : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int fetchTimeout READ fetchTimeout WRITE setFetchTimeout)
public:
    SOJsExtension(QObject * parent = nullptr);

    Q_INVOKABLE int fetchTimeout() const { return m_fetchTimeout; }
    Q_INVOKABLE void setFetchTimeout(int ms) { m_fetchTimeout = ms; }
    Q_INVOKABLE bool prefetchQuestionBody(const QString & question);
    Q_INVOKABLE QString getQuestionBody(const QString & question);
    Q_INVOKABLE QString getStatus(const QString & question) const;

private:
    NetworkReplyCache<qint64> m_cache;
    int m_fetchTimeout = 3000;
    qint64 m_maxQuestionBodySize = 128*1024;

    CachedReply * getItem(qint64 id);
};
