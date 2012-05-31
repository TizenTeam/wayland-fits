#include <Elementary.h>
#include <Ecore.h>

#include "application.h"
#include "window.h"

BOOST_AUTO_TEST_SUITE(Wayland_EFL_Button_Suite)

WAYLAND_EFL_AUTO_TEST_CASE(efl_button_resize)
{
	Window win;
	win.show();

	EvasObject btn(elm_button_add(win));
	btn.show();

	btn.setSize(120, 30);

	Application::yield();

	BOOST_CHECK_EQUAL(btn.getWidth(), 120);
	BOOST_CHECK_EQUAL(btn.getHeight(), 30);

	btn.setSize(75, 75);

	Application::yield();

	BOOST_CHECK_EQUAL(btn.getWidth(), 75);
	BOOST_CHECK_EQUAL(btn.getHeight(), 75);
}

WAYLAND_EFL_AUTO_TEST_CASE(efl_button_move)
{
	Window win;
	win.show();

	EvasObject btn(elm_button_add(win));
	btn.show();

	btn.setPosition(60, 15);

	Application::yield();

	BOOST_CHECK_EQUAL(btn.getX(), 60);
	BOOST_CHECK_EQUAL(btn.getY(), 15);

	btn.setPosition(10, 10);

	Application::yield();

	BOOST_CHECK_EQUAL(btn.getX(), 10);
	BOOST_CHECK_EQUAL(btn.getY(), 10);
}

BOOST_AUTO_TEST_SUITE_END()