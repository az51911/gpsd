/* libgps.h -- prototypes for internals of the libgps library */
/*
 * This file is Copyright (c) 2010 by the GPSD project
 * BSD terms apply: see the file COPYING in the distribution root for details.
 */
#ifndef _GPSD_LIBGPS_H_
#define _GPSD_LIBGPS_H_

/* 
 * first member of each kind of privdata structure must be named 
 * 'export' and must be of this time.  It's how we do runtime 
 * dispatch to the different transports.
 */
enum export_t {sockets, shm, dbus};

extern int gps_sock_open(/*@null@*/const char *, /*@null@*/const char *, 
		      /*@out@*/struct gps_data_t *);
extern int gps_sock_close(struct gps_data_t *);
extern int gps_sock_send(struct gps_data_t *, const char *);
extern int gps_sock_read(/*@out@*/struct gps_data_t *);
extern bool gps_sock_waiting(const struct gps_data_t *, int);
extern int gps_sock_stream(struct gps_data_t *, unsigned int, /*@null@*/void *);
extern const char /*@observer@*/ *gps_sock_data(const struct gps_data_t *);
extern int gps_sock_mainloop(struct gps_data_t *, int timeout,
			      void (*)(struct gps_data_t *));
extern int gps_shm_mainloop(struct gps_data_t *, int timeout,
			      void (*)(struct gps_data_t *));

extern int gps_shm_open(/*@out@*/struct gps_data_t *);
extern void gps_shm_close(struct gps_data_t *);
extern int gps_shm_read(struct gps_data_t *);

extern int gps_dbus_open(struct gps_data_t *);
extern int gps_dbus_mainloop(struct gps_data_t *, int timeout,
			      void (*)(struct gps_data_t *));


#endif /* _GPSD_LIBGPS_H_ */