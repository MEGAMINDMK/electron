// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef SHELL_BROWSER_EXTENSIONS_ATOM_EXTENSION_HOST_DELEGATE_H_
#define SHELL_BROWSER_EXTENSIONS_ATOM_EXTENSION_HOST_DELEGATE_H_

#include <memory>
#include <string>

#include "base/macros.h"
#include "extensions/browser/extension_host_delegate.h"

namespace extensions {

// A minimal ExtensionHostDelegate.
class AtomExtensionHostDelegate : public ExtensionHostDelegate {
 public:
  AtomExtensionHostDelegate();
  ~AtomExtensionHostDelegate() override;

  // ExtensionHostDelegate implementation.
  void OnExtensionHostCreated(content::WebContents* web_contents) override;
  void OnRenderViewCreatedForBackgroundPage(ExtensionHost* host) override;
  content::JavaScriptDialogManager* GetJavaScriptDialogManager() override;
  void CreateTab(std::unique_ptr<content::WebContents> web_contents,
                 const std::string& extension_id,
                 WindowOpenDisposition disposition,
                 const gfx::Rect& initial_rect,
                 bool user_gesture) override;
  void ProcessMediaAccessRequest(content::WebContents* web_contents,
                                 const content::MediaStreamRequest& request,
                                 content::MediaResponseCallback callback,
                                 const Extension* extension) override;
  bool CheckMediaAccessPermission(content::RenderFrameHost* render_frame_host,
                                  const GURL& security_origin,
                                  blink::mojom::MediaStreamType type,
                                  const Extension* extension) override;
  content::PictureInPictureResult EnterPictureInPicture(
      content::WebContents* web_contents,
      const viz::SurfaceId& surface_id,
      const gfx::Size& natural_size) override;
  void ExitPictureInPicture() override;

 private:
  DISALLOW_COPY_AND_ASSIGN(AtomExtensionHostDelegate);
};

}  // namespace extensions

#endif  // SHELL_BROWSER_EXTENSIONS_ATOM_EXTENSION_HOST_DELEGATE_H_
