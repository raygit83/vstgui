#ifndef __uicolorscontroller__
#define __uicolorscontroller__

#include "../uidescription.h"

#if VSTGUI_LIVE_EDITING

#include "uiselection.h"
#include "uiundomanager.h"
#include "iaction.h"

namespace VSTGUI {
class UIColorsDataSource;

//----------------------------------------------------------------------------------------------------
class UIColorsController : public CBaseObject, public DelegationController
{
public:
	UIColorsController (IController* baseController, UIDescription* description, IActionPerformer* actionPerformer);
	~UIColorsController ();

protected:
	CView* createView (const UIAttributes& attributes, IUIDescription* description);
	CView* verifyView (CView* view, const UIAttributes& attributes, IUIDescription* description);
	CControlListener* getControlListener (UTF8StringPtr name);
	void valueChanged (CControl* pControl);

	SharedPointer<UIDescription> editDescription;
	IActionPerformer* actionPerformer;
	UIColorsDataSource* dataSource;
	
	enum {
		kAddTag = 0,
		kRemoveTag,
		kSearchTag,
	};
};

} // namespace

#endif // VSTGUI_LIVE_EDITING

#endif // __uicolorscontroller__
