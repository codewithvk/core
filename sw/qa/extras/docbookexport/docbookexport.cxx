/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#include <swmodeltestbase.hxx>

namespace
{
class DocbookExportTest : public SwModelTestBase
{
public:
    DocbookExportTest() :
        SwModelTestBase("/sw/qa/extras/docbookexport/data/", "DocBook File")
    {}
};

#define DECLARE_DOCBOOKEXPORT_TEST(TestName, filename) DECLARE_SW_EXPORT_TEST(TestName, filename, nullptr, DocbookExportTest)

DECLARE_DOCBOOKEXPORT_TEST(testsimple, "simple.docx")
{
    xmlDocUniquePtr pDoc = parseXml(maTempFile);
    CPPUNIT_ASSERT(pDoc);

    assertXPathContent(pDoc, "/article/para"_ostr, "aaaa");
}

/* the test actually should crash with this file */
DECLARE_DOCBOOKEXPORT_TEST(testtdf91095, "tdf91095.docx")
{
    xmlDocUniquePtr pDoc = parseXml(maTempFile);
    CPPUNIT_ASSERT(pDoc);
}

} // end of anonymous namespace
CPPUNIT_PLUGIN_IMPLEMENT();

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
