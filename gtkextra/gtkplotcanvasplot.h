/* gtkplotcanvas - gtkplot canvas widget for gtk+
 * Copyright 1999-2001  Adrian E. Feiguin <feiguin@ifir.edu.ar>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifndef __GTK_PLOT_CANVAS_PLOT_H__
#define __GTK_PLOT_CANVAS_PLOT_H__

#define GTK_PLOT_CANVAS_PLOT(obj)        G_TYPE_CHECK_INSTANCE_CAST (obj, gtk_plot_canvas_plot_get_type (), GtkPlotCanvasPlot)
#define GTK_PLOT_CANVAS_PLOT_CLASS(klass) G_TYPE_CHECK_CLASS_CAST (klass, gtk_plot_canvas_plot_get_type(), GtkPlotCanvasPlotClass)
#define GTK_IS_PLOT_CANVAS_PLOT(obj)     G_TYPE_CHECK_INSTANCE_TYPE (obj, gtk_plot_canvas_plot_get_type ())
#define G_TYPE_PLOT_CANVAS_PLOT (gtk_plot_canvas_plot_get_type ())
#define GTK_PLOT_CANVAS_PLOT_SELECT_POINT(plot)  (plot->flags & GTK_PLOT_CANVAS_PLOT_SELECT_POINT)
#define GTK_PLOT_CANVAS_PLOT_DND_POINT(plot)  (plot->flags & GTK_PLOT_CANVAS_PLOT_DND_POINT)
#define GTK_PLOT_CANVAS_PLOT_FLAGS(plot)     (GTK_PLOT_CANVAS_PLOT(plot)->flags)
#define GTK_PLOT_CANVAS_PLOT_SET_FLAGS(plot, flags)  (GTK_PLOT_CANVAS_PLOT_FLAGS(plot) |= (flags))
#define GTK_PLOT_CANVAS_PLOT_UNSET_FLAGS(plot, flags)  (GTK_PLOT_CANVAS_PLOT_FLAGS(plot) &= ~(flags))



#include <gdk/gdk.h>
#include "gtkplotpc.h"
#include "gtkplot.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

typedef struct _GtkPlotCanvasPlot	GtkPlotCanvasPlot;
typedef struct _GtkPlotCanvasPlotClass	GtkPlotCanvasPlotClass;

typedef enum
{
  GTK_PLOT_CANVAS_PLOT_OUT,
  GTK_PLOT_CANVAS_PLOT_IN_PLOT,
  GTK_PLOT_CANVAS_PLOT_IN_LEGENDS,
  GTK_PLOT_CANVAS_PLOT_IN_TITLE,
  GTK_PLOT_CANVAS_PLOT_IN_AXIS,
  GTK_PLOT_CANVAS_PLOT_IN_DATA,
  GTK_PLOT_CANVAS_PLOT_IN_GRADIENT,
  GTK_PLOT_CANVAS_PLOT_IN_MARKER,
} GtkPlotCanvasPlotPos;

/**
 * GtkPlotCanvasPlotFlags:
 * @GTK_PLOT_CANVAS_PLOT_SELECT_POINT: Select point
 * @GTK_PLOT_CANVAS_PLOT_DND_POINT: DnD point
 *
 * Selection and DND mode of #GtkPlotCanvas
 *
 **/
typedef enum
{
      GTK_PLOT_CANVAS_PLOT_SELECT_POINT  =       1 << 0, /* Select point */
      GTK_PLOT_CANVAS_PLOT_DND_POINT     =       1 << 1, /* DnD point */
} GtkPlotCanvasPlotFlags;

/**
 * GtkPlotCanvasPlot:
 *
 * The GtkPlotBar struct contains only private data.
 * It should only be accessed through the functions described below.
 */
struct _GtkPlotCanvasPlot
{
  GtkPlotCanvasChild parent;

  GtkPlotCanvasPlotPos pos;

  GtkPlotAxis *axis;
  GtkPlotData *data;
  GtkPlotMarker *marker;
  gint datapoint;

  GtkPlotCanvasPlotFlags flags;

  GtkPlot *plot;
};

struct _GtkPlotCanvasPlotClass
{
  GtkPlotCanvasChildClass parent_class;
};


GType 		gtk_plot_canvas_plot_get_type	(void);
GtkPlotCanvasChild * 
		gtk_plot_canvas_plot_new	(GtkPlot *plot);

GtkPlotCanvasPlotFlags gtk_plot_canvas_plot_flags(GtkPlotCanvasPlot *plot);
void gtk_plot_canvas_plot_set_flags(GtkPlotCanvasPlot *plot, GtkPlotCanvasPlotFlags flags);
void gtk_plot_canvas_plot_unset_flags(GtkPlotCanvasPlot *plot, GtkPlotCanvasPlotFlags flags);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __GTK_PLOT_CANVAS_PLOT_H__ */
