/*======================================================================
 FILE: icalspanlist.h
 CREATOR: eric 21 Aug 2000

 (C) COPYRIGHT 2000, Eric Busboom <eric@civicknowledge.com>

 This library is free software; you can redistribute it and/or modify
 it under the terms of either:

    The LGPL as published by the Free Software Foundation, version
    2.1, available at: https://www.gnu.org/licenses/lgpl-2.1.html

 Or:

    The Mozilla Public License Version 2.0. You may obtain a copy of
    the License at https://www.mozilla.org/MPL/
=========================================================================*/
#ifndef ICALSPANLIST_H
#define ICALSPANLIST_H

#include "libical_icalss_export.h"
#include "icalset.h"

/** @file icalspanlist.h
 *  @brief Code that supports collections of free/busy spans of time
 */

typedef struct icalspanlist_impl icalspanlist;

/** @brief Constructor
 * Makes a free list from a set of component. Start and end should be in UTC
 */

LIBICAL_ICALSS_EXPORT icalspanlist *icalspanlist_new(icalset *set,
                                                     struct icaltimetype start,
                                                     struct icaltimetype end);

/** @brief Destructor
 */
LIBICAL_ICALSS_EXPORT void icalspanlist_free(icalspanlist *spl);

/** Gets first next free time after time t. all times are in UTC. */
LIBICAL_ICALSS_EXPORT struct icalperiodtype icalspanlist_next_free_time(icalspanlist *sl,
                                                                        struct icaltimetype t);

LIBICAL_ICALSS_EXPORT void icalspanlist_dump(icalspanlist *s);

/** @brief Returns a valid VFREEBUSY component for this span */
LIBICAL_ICALSS_EXPORT icalcomponent *icalspanlist_as_vfreebusy(icalspanlist *sl,
                                                               const char *organizer,
                                                               const char *attendee);

/** @brief Returns an integer matrix of total events per delta_t timespan */
LIBICAL_ICALSS_EXPORT int *icalspanlist_as_freebusy_matrix(icalspanlist *span, int delta_t);

/** @brief Constructs an icalspanlist from a VFREEBUSY component */
LIBICAL_ICALSS_EXPORT icalspanlist *icalspanlist_from_vfreebusy(icalcomponent *comp);

#endif
