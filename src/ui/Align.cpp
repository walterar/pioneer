#include "Align.h"

namespace UI {

Point Align::PreferredSize()
{
	if (!GetInnerWidget()) return Point();
	return GetInnerWidget()->PreferredSize();
}

void Align::Layout()
{
	if (!GetInnerWidget()) return;

	const Point &size = GetSize();
	const Point &preferred = GetInnerWidget()->PreferredSize();

	Point pos;

	switch (m_direction) {
		case TOP_LEFT:
		case LEFT:
		case BOTTOM_LEFT:
			pos.x = 0.0f;
			break;

		case TOP:
		case MIDDLE:
		case BOTTOM:
			pos.x = std::max(0.0f, floorf((size.x-preferred.x)/2));
			break;

		case TOP_RIGHT:
		case RIGHT:
		case BOTTOM_RIGHT:
			pos.x = std::max(0.0f, floorf(size.x-preferred.x));
			break;
	}

	switch (m_direction) {
		case TOP_LEFT:
		case TOP:
		case TOP_RIGHT:
			pos.y = 0.0f;
			break;

		case LEFT:
		case MIDDLE:
		case RIGHT:
			pos.y = std::max(0.0f, floorf((size.y-preferred.y)/2));
			break;

		case BOTTOM_LEFT:
		case BOTTOM:
		case BOTTOM_RIGHT:
			pos.y = std::max(0.0f, floorf(size.y-preferred.y));
			break;
	}

	SetWidgetDimensions(GetInnerWidget(), pos, Point(std::min(size.x, preferred.x), std::min(size.y, preferred.y)));
	GetInnerWidget()->Layout();
}

}
