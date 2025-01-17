/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 *
 * This file incorporates work covered by the following license notice:
 *
 *   Licensed to the Apache Software Foundation (ASF) under one or more
 *   contributor license agreements. See the NOTICE file distributed
 *   with this work for additional information regarding copyright
 *   ownership. The ASF licenses this file to you under the Apache
 *   License, Version 2.0 (the "License"); you may not use this file
 *   except in compliance with the License. You may obtain a copy of
 *   the License at http://www.apache.org/licenses/LICENSE-2.0 .
 */

#ifndef INCLUDED_VCL_INC_HEADLESS_SVPBMP_HXX
#define INCLUDED_VCL_INC_HEADLESS_SVPBMP_HXX

#include <sal/config.h>

#include <salbmp.hxx>
#include <basegfx/utils/systemdependentdata.hxx>
#include <optional>

class VCL_DLLPUBLIC SvpSalBitmap final : public SalBitmap, public basegfx::SystemDependentDataHolder // MM02
{
    std::optional<BitmapBuffer> moDIB;
public:
             SvpSalBitmap();
    virtual ~SvpSalBitmap() override;

    bool        ImplCreate(const Size& rSize,
                           vcl::PixelFormat ePixelFormat,
                           const BitmapPalette& rPalette,
                           bool bClear);

    // SalBitmap
    virtual bool            Create(const Size& rSize,
                                   vcl::PixelFormat ePixelFormat,
                                   const BitmapPalette& rPalette) override;
    virtual bool            Create( const SalBitmap& rSalBmp ) override;
    virtual bool            Create( const SalBitmap& rSalBmp,
                                    SalGraphics* pGraphics ) override;
    virtual bool            Create(const SalBitmap& rSalBmp,
                                   vcl::PixelFormat eNewPixelFormat) override;
    virtual bool            Create( const css::uno::Reference< css::rendering::XBitmapCanvas >& rBitmapCanvas,
                                    Size& rSize,
                                    bool bMask = false ) override;
    void                    Create(const std::optional<BitmapBuffer> & pBuf);
    const BitmapBuffer*     GetBuffer() const
    {
        return moDIB ? &*moDIB : nullptr;
    }
    virtual void            Destroy() final override;
    virtual Size            GetSize() const override;
    virtual sal_uInt16      GetBitCount() const override;

    virtual BitmapBuffer*   AcquireBuffer( BitmapAccessMode nMode ) override;
    virtual void            ReleaseBuffer( BitmapBuffer* pBuffer, BitmapAccessMode nMode ) override;
    virtual bool            GetSystemData( BitmapSystemData& rData ) override;

    virtual bool            ScalingSupported() const override;
    virtual bool            Scale( const double& rScaleX, const double& rScaleY, BmpScaleFlag nScaleFlag ) override;
    virtual bool            Replace( const Color& rSearchColor, const Color& rReplaceColor, sal_uInt8 nTol ) override;

    virtual const basegfx::SystemDependentDataHolder* accessSystemDependentDataHolder() const override;
};

#endif // INCLUDED_VCL_INC_HEADLESS_SVPBMP_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
