/*
 * QDigiDocClient
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#pragma once

#include <QtWidgets/QTreeView>

class DocumentModel;
class DigiDoc;

class TreeWidget: public QTreeView
{
	Q_OBJECT
public:
	explicit TreeWidget( QWidget *parent = 0 );
	~TreeWidget();

	void setDocumentModel( DocumentModel *model );
	void setDigiDoc( DigiDoc *docPtr );

private Q_SLOTS:
	void clicked( const QModelIndex &index );

private:
	void keyPressEvent( QKeyEvent *e );
	void setPreviewIndex( const QModelIndex &index );
	void showPreview();
	void hidePreview();

	DocumentModel *m;
	DigiDoc	*doc;
};
