/*
 *  Window.cpp
 *  a2
 *
 *  Created by Jeff Nicholson on 11-10-17.
 *  Copyright 2011 University of Calgary. All rights reserved.
 *
 */

#include "Window.h"

Window::Window(QWidget *parent) : QMainWindow(parent)
{

	//init 
	setWindowTitle(tr("Convex Hull Visualizer"));
	
	glWidget = new GLWidget;

	centralWidget = new QWidget;
	setCentralWidget(centralWidget);
	
	mainLayout = new QHBoxLayout;
	controlLayout = new QVBoxLayout;

	// set up buttons
	clearPointsButton = new QPushButton("Clear Points");
	connect(clearPointsButton, SIGNAL(clicked()), glWidget, SLOT(clearPoints()));

	toggleConvexHullButton = new QPushButton("Convex Hull");
	toggleConvexHullButton->setCheckable(true);
	toggleConvexHullButton->setDown(true);
	connect(toggleConvexHullButton, SIGNAL(toggled(bool)), glWidget, SLOT(toggleConvexHull(bool)));

	// add controls to controlLayout
	controlLayout->addWidget(toggleConvexHullButton);
	controlLayout->addWidget(clearPointsButton);

	// add main widgets and layouts
	mainLayout->addWidget(glWidget);
	mainLayout->addLayout(controlLayout);
	centralWidget->setLayout(mainLayout);
}

