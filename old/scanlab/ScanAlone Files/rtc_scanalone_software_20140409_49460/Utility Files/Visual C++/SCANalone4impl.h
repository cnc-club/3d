//-----------------------------------------------------------------------------
//  File: SCANalone4impl.h           (c) Copyright 2001,... 2013 by SCANLAB AG.
//-----------------------------------------------------------------------------
//
//
//
//  Abstract
//      SCANalone4 function prototypes for implicitly linking - also known as
//      static load linking - to the SCANalone4.DLL.
//
//  Author
//      Gerald Schmid
//
//  Revision History
//      +-----+---------+--------+------------------------------------------+
//      | Mod |  Date   | Author | Description                              |
//      +-----+---------+--------+------------------------------------------+
//      | 0.0 | 17Oct03 |   GS   | * initial release                        |
//      | 1.0 | 24Jul13 |   GS   | * n_get_serial_number_32 and             |
//      |     |         |        |   get_serial_number_32 added.            |
//      |     |         |        |                                          |
//      +-----+---------+--------+------------------------------------------+
//
//  NOTE
//      For building an executable, you must link with the (Visual C++)
//      import library SCANalone4.LIB.
//
//-----------------------------------------------------------------------------

_declspec(dllimport) unsigned short __stdcall scanalone_count_cards(void);
_declspec(dllimport) void __stdcall select_rtc(unsigned short n);
_declspec(dllimport) void __stdcall writemem(unsigned short bn, long adr, unsigned short n, unsigned short *memptr);
_declspec(dllimport) void __stdcall readmem(unsigned short bn, long adr, unsigned short n, unsigned short *memptr);
_declspec(dllimport) long __stdcall n_usb_status(unsigned short n);
_declspec(dllimport) long __stdcall usb_status(void);
_declspec(dllimport) short __stdcall n_load_correction_file(unsigned short n, const char* filename, short cortable, double kx, double ky, double phi, double xoffset, double yoffset);
_declspec(dllimport) short __stdcall load_correction_file(const char* filename, short cortable, double kx, double ky, double phi, double xoffset, double yoffset);
_declspec(dllimport) short __stdcall n_load_cor(unsigned short n, const char* filename);
_declspec(dllimport) short __stdcall load_cor(const char* filename);
_declspec(dllimport) short __stdcall n_load_program_file(unsigned short n, const char* name);
_declspec(dllimport) short __stdcall load_program_file(const char* name);
_declspec(dllimport) short __stdcall n_load_pro(unsigned short n, const char* filename);
_declspec(dllimport) short __stdcall load_pro(const char* filename);
_declspec(dllimport) short __stdcall n_load_varpolydelay(unsigned short n, const char* stbfilename, unsigned short tableno);
_declspec(dllimport) short __stdcall load_varpolydelay(const char* stbfilename, unsigned short tableno);
_declspec(dllimport) short __stdcall n_load_z_table(unsigned short n, double a, double b, double c);
_declspec(dllimport) short __stdcall load_z_table(double a, double b, double c);
_declspec(dllimport) void __stdcall n_get_waveform(unsigned short n, unsigned short channel, unsigned short stopp, short *memptr);
_declspec(dllimport) void __stdcall get_waveform(unsigned short channel, unsigned short stopp, short *memptr);
_declspec(dllimport) void __stdcall n_get_status(unsigned short n, unsigned short *busy, long *position);
_declspec(dllimport) void __stdcall get_status(unsigned short *busy, long *position);
_declspec(dllimport) unsigned short __stdcall n_read_status(unsigned short n);
_declspec(dllimport) unsigned short __stdcall read_status(void);
_declspec(dllimport) unsigned short __stdcall get_dll_version(void);
_declspec(dllimport) long __stdcall n_get_input_pointer(unsigned short n);
_declspec(dllimport) long __stdcall get_input_pointer(void);
_declspec(dllimport) void __stdcall n_set_input_pointer(unsigned short n, long pointer);
_declspec(dllimport) void __stdcall set_input_pointer(long pointer);
_declspec(dllimport) void __stdcall n_set_start_list_1(unsigned short n);
_declspec(dllimport) void __stdcall set_start_list_1(void);
_declspec(dllimport) void __stdcall n_set_start_list_2(unsigned short n);
_declspec(dllimport) void __stdcall set_start_list_2(void);
_declspec(dllimport) void __stdcall n_set_start_list(unsigned short n, unsigned short listno);
_declspec(dllimport) void __stdcall set_start_list(unsigned short listno);
_declspec(dllimport) void __stdcall n_execute_list_1(unsigned short n);
_declspec(dllimport) void __stdcall execute_list_1(void);
_declspec(dllimport) void __stdcall n_execute_list_2(unsigned short n);
_declspec(dllimport) void __stdcall execute_list_2(void);
_declspec(dllimport) void __stdcall n_execute_list(unsigned short n, unsigned short listno);
_declspec(dllimport) void __stdcall execute_list(unsigned short listno);
_declspec(dllimport) void __stdcall n_write_8bit_port(unsigned short n, unsigned short value);
_declspec(dllimport) void __stdcall write_8bit_port(unsigned short value);
_declspec(dllimport) void __stdcall n_write_io_port(unsigned short n, unsigned short value);
_declspec(dllimport) void __stdcall write_io_port(unsigned short value);
_declspec(dllimport) void __stdcall n_auto_change(unsigned short n);
_declspec(dllimport) void __stdcall auto_change(void);
_declspec(dllimport) void __stdcall n_aut_change(unsigned short n);
_declspec(dllimport) void __stdcall aut_change(void);
_declspec(dllimport) void __stdcall n_start_loop(unsigned short n);
_declspec(dllimport) void __stdcall start_loop(void);
_declspec(dllimport) void __stdcall n_quit_loop(unsigned short n);
_declspec(dllimport) void __stdcall quit_loop(void);
_declspec(dllimport) void __stdcall n_stop_execution(unsigned short n);
_declspec(dllimport) void __stdcall stop_execution(void);
_declspec(dllimport) void __stdcall n_dsp_start(unsigned short n);
_declspec(dllimport) void __stdcall dsp_start(void);
_declspec(dllimport) unsigned short __stdcall n_read_io_port(unsigned short n);
_declspec(dllimport) unsigned short __stdcall read_io_port(void);
_declspec(dllimport) void __stdcall n_write_da_1(unsigned short n, unsigned short value);
_declspec(dllimport) void __stdcall write_da_1(unsigned short value);
_declspec(dllimport) void __stdcall n_write_da_2(unsigned short n, unsigned short value);
_declspec(dllimport) void __stdcall write_da_2(unsigned short value);
_declspec(dllimport) void __stdcall n_write_da_x(unsigned short n, unsigned short x, unsigned short value);
_declspec(dllimport) void __stdcall write_da_x(unsigned short x, unsigned short value);
_declspec(dllimport) void __stdcall n_set_max_counts(unsigned short n, long counts);
_declspec(dllimport) void __stdcall set_max_counts(long counts);
_declspec(dllimport) long __stdcall n_get_counts(unsigned short n);
_declspec(dllimport) long __stdcall get_counts(void);
_declspec(dllimport) void __stdcall n_set_matrix(unsigned short n, double m11, double m12, double m21, double m22);
_declspec(dllimport) void __stdcall set_matrix(double m11, double m12, double m21, double m22);
_declspec(dllimport) void __stdcall n_set_offset(unsigned short n, short xoffset, short yoffset);
_declspec(dllimport) void __stdcall set_offset(short xoffset, short yoffset);
_declspec(dllimport) void __stdcall n_goto_xy(unsigned short n, short x, short y);
_declspec(dllimport) void __stdcall goto_xy(short x, short y);
_declspec(dllimport) void __stdcall n_goto_xyz(unsigned short n, short x, short y, short z);
_declspec(dllimport) void __stdcall goto_xyz(short x, short y, short z);
_declspec(dllimport) unsigned short __stdcall n_get_hex_version(unsigned short n);
_declspec(dllimport) unsigned short __stdcall get_hex_version(void);
_declspec(dllimport) void __stdcall n_enable_laser(unsigned short n);
_declspec(dllimport) void __stdcall enable_laser(void);
_declspec(dllimport) void __stdcall n_disable_laser(unsigned short n);
_declspec(dllimport) void __stdcall disable_laser(void);
_declspec(dllimport) void __stdcall n_stop_list(unsigned short n);
_declspec(dllimport) void __stdcall stop_list(void);
_declspec(dllimport) void __stdcall n_restart_list(unsigned short n);
_declspec(dllimport) void __stdcall restart_list(void);
_declspec(dllimport) unsigned short __stdcall n_get_rtc_version(unsigned short n);
_declspec(dllimport) unsigned short __stdcall get_rtc_version(void);
_declspec(dllimport) void __stdcall n_get_xy_pos(unsigned short n, short *x, short *y);
_declspec(dllimport) void __stdcall get_xy_pos(short *x, short *y);
_declspec(dllimport) void __stdcall n_get_xyz_pos(unsigned short n, short *x, short *y, short *z);
_declspec(dllimport) void __stdcall get_xyz_pos(short *x, short *y, short *z);
_declspec(dllimport) void __stdcall n_select_list(unsigned short n, unsigned short list_2);
_declspec(dllimport) void __stdcall select_list(unsigned short list_2);
_declspec(dllimport) void __stdcall n_set_extstartpos(unsigned short n, long position);
_declspec(dllimport) void __stdcall set_extstartpos(long position);
_declspec(dllimport) void __stdcall n_z_out(unsigned short n, short z);
_declspec(dllimport) void __stdcall z_out(short z);
_declspec(dllimport) void __stdcall n_set_firstpulse_killer(unsigned short n, unsigned short fpk);
_declspec(dllimport) void __stdcall set_firstpulse_killer(unsigned short fpk);
_declspec(dllimport) void __stdcall n_set_standby(unsigned short n, unsigned short half_period, unsigned short pulse);
_declspec(dllimport) void __stdcall set_standby(unsigned short half_period, unsigned short pulse);
_declspec(dllimport) void __stdcall n_laser_signal_on(unsigned short n);
_declspec(dllimport) void __stdcall laser_signal_on(void);
_declspec(dllimport) void __stdcall n_laser_signal_off(unsigned short n);
_declspec(dllimport) void __stdcall laser_signal_off(void);
_declspec(dllimport) void __stdcall n_set_delay_mode(unsigned short n, unsigned short varpoly, unsigned short directmove3d, unsigned short edgelevel, unsigned short minjumpdelay, unsigned short jumplengthlimit);
_declspec(dllimport) void __stdcall set_delay_mode(unsigned short varpoly, unsigned short directmove3d, unsigned short edgelevel, unsigned short minjumpdelay, unsigned short jumplengthlimit);
_declspec(dllimport) void __stdcall n_set_piso_control(unsigned short n, unsigned short l1, unsigned short l2);
_declspec(dllimport) void __stdcall set_piso_control(unsigned short l1, unsigned short l2);
_declspec(dllimport) void __stdcall n_select_status(unsigned short n, unsigned short mode);
_declspec(dllimport) void __stdcall select_status(unsigned short mode);
_declspec(dllimport) void __stdcall n_get_encoder(unsigned short n, short *zx, short *zy);
_declspec(dllimport) void __stdcall get_encoder(short *zx, short *zy);
_declspec(dllimport) void __stdcall n_select_cor_table(unsigned short n, unsigned short heada, unsigned short headb);
_declspec(dllimport) void __stdcall select_cor_table(unsigned short heada, unsigned short headb);
_declspec(dllimport) void __stdcall n_execute_at_pointer(unsigned short n, long position);
_declspec(dllimport) void __stdcall execute_at_pointer(long position);
_declspec(dllimport) unsigned short __stdcall n_get_head_status(unsigned short n, unsigned short head);
_declspec(dllimport) unsigned short __stdcall get_head_status(unsigned short head);
_declspec(dllimport) void __stdcall n_simulate_encoder(unsigned short n, unsigned short channel);
_declspec(dllimport) void __stdcall simulate_encoder(unsigned short channel);
_declspec(dllimport) void __stdcall n_release_wait(unsigned short n);
_declspec(dllimport) void __stdcall release_wait(void);
_declspec(dllimport) unsigned short __stdcall n_get_wait_status(unsigned short n);
_declspec(dllimport) unsigned short __stdcall get_wait_status(void);
_declspec(dllimport) void __stdcall n_set_control_mode(unsigned short n, unsigned short mode);
_declspec(dllimport) void __stdcall set_control_mode(unsigned short mode);
_declspec(dllimport) void __stdcall n_set_laser_mode(unsigned short n, unsigned short mode);
_declspec(dllimport) void __stdcall set_laser_mode(unsigned short mode);
_declspec(dllimport) void __stdcall n_set_ext_start_delay(unsigned short n, short delay, short encoder);
_declspec(dllimport) void __stdcall set_ext_start_delay(short delay, short encoder);
_declspec(dllimport) void __stdcall n_home_position(unsigned short n, short xhome, short yhome);
_declspec(dllimport) void __stdcall home_position(short xhome, short yhome);
_declspec(dllimport) unsigned short __stdcall n_read_ad_x(unsigned short n, unsigned short x);
_declspec(dllimport) unsigned short __stdcall read_ad_x(unsigned short x);
_declspec(dllimport) short __stdcall n_get_z_distance(unsigned short n, short x, short y, short z);
_declspec(dllimport) short __stdcall get_z_distance(short x, short y, short z);
_declspec(dllimport) unsigned short __stdcall n_get_startstop_info(unsigned short n);
_declspec(dllimport) unsigned short __stdcall get_startstop_info(void);
_declspec(dllimport) unsigned short __stdcall n_get_marking_info(unsigned short n);
_declspec(dllimport) unsigned short __stdcall get_marking_info(void);
_declspec(dllimport) unsigned short __stdcall n_get_io_status(unsigned short n);
_declspec(dllimport) unsigned short __stdcall get_io_status(void);
_declspec(dllimport) double __stdcall n_get_time(unsigned short n);
_declspec(dllimport) double __stdcall get_time(void);
_declspec(dllimport) void __stdcall n_set_defocus(unsigned short n, short value);
_declspec(dllimport) void __stdcall set_defocus(short value);
_declspec(dllimport) void __stdcall n_set_softstart_mode(unsigned short n, unsigned short mode, unsigned short number, unsigned short restartdelay);
_declspec(dllimport) void __stdcall set_softstart_mode(unsigned short mode, unsigned short number, unsigned short restartdelay);
_declspec(dllimport) void __stdcall n_set_softstart_level(unsigned short n, unsigned short index, unsigned short level);
_declspec(dllimport) void __stdcall set_softstart_level(unsigned short index, unsigned short level);
_declspec(dllimport) void __stdcall n_control_command(unsigned short n, unsigned short head, unsigned short axis, unsigned short data);
_declspec(dllimport) void __stdcall control_command(unsigned short head, unsigned short axis, unsigned short data);
_declspec(dllimport) void __stdcall n_set_rot_center(unsigned short n, long center_x, long center_y);
_declspec(dllimport) void __stdcall set_rot_center(long center_x, long center_y);
_declspec(dllimport) void __stdcall n_auto_change_pos(unsigned short n, long start);
_declspec(dllimport) void __stdcall auto_change_pos(long start);
_declspec(dllimport) short __stdcall n_get_value(unsigned short n, unsigned short signal);
_declspec(dllimport) short __stdcall get_value(unsigned short signal);
_declspec(dllimport) void __stdcall n_set_io_bit(unsigned short n, unsigned short mask1);
_declspec(dllimport) void __stdcall set_io_bit(unsigned short mask1);
_declspec(dllimport) void __stdcall n_clear_io_bit(unsigned short n, unsigned short mask0);
_declspec(dllimport) void __stdcall clear_io_bit(unsigned short mask0);
_declspec(dllimport) void __stdcall n_set_duty_cycle_table(unsigned short n, unsigned short index, unsigned short dutycycle);
_declspec(dllimport) void __stdcall set_duty_cycle_table(unsigned short index, unsigned short dutycycle);
_declspec(dllimport) short __stdcall n_store_on_mmc(unsigned short n);
_declspec(dllimport) short __stdcall store_on_mmc(void);
_declspec(dllimport) unsigned short __stdcall n_get_serial_number(unsigned short n);
_declspec(dllimport) unsigned short __stdcall get_serial_number(void);
_declspec(dllimport) long __stdcall n_get_serial_number_32(unsigned short n);
_declspec(dllimport) long __stdcall get_serial_number_32(void);
_declspec(dllimport) void __stdcall n_measurement_status(unsigned short n, unsigned short *busy, unsigned short *position);
_declspec(dllimport) void __stdcall measurement_status(unsigned short *busy, unsigned short *position);
_declspec(dllimport) void __stdcall n_clear_list(unsigned short n);
_declspec(dllimport) void __stdcall clear_list(void);
_declspec(dllimport) void __stdcall n_set_char_table(unsigned short n, unsigned short ch, long listpos);
_declspec(dllimport) void __stdcall set_char_table(unsigned short ch, long listpos);
_declspec(dllimport) void __stdcall n_time_update(unsigned short n);
_declspec(dllimport) void __stdcall time_update(void);
_declspec(dllimport) void __stdcall n_set_serial(unsigned short n, long no);
_declspec(dllimport) void __stdcall set_serial(long no);
_declspec(dllimport) long __stdcall n_memory_test(unsigned short n);
_declspec(dllimport) long __stdcall memory_test(void);
_declspec(dllimport) void __stdcall n_list_nop(unsigned short n);
_declspec(dllimport) void __stdcall list_nop(void);
_declspec(dllimport) void __stdcall n_set_end_of_list(unsigned short n);
_declspec(dllimport) void __stdcall set_end_of_list(void);
_declspec(dllimport) void __stdcall n_jump_abs(unsigned short n, short x, short y);
_declspec(dllimport) void __stdcall jump_abs(short x, short y);
_declspec(dllimport) void __stdcall n_jump_abs_3d(unsigned short n, short x, short y, short z);
_declspec(dllimport) void __stdcall jump_abs_3d(short x, short y, short z);
_declspec(dllimport) void __stdcall n_mark_abs(unsigned short n, short x, short y);
_declspec(dllimport) void __stdcall mark_abs(short x, short y);
_declspec(dllimport) void __stdcall n_mark_abs_3d(unsigned short n, short x, short y, short z);
_declspec(dllimport) void __stdcall mark_abs_3d(short x, short y, short z);
_declspec(dllimport) void __stdcall n_jump_rel(unsigned short n, short dx, short dy);
_declspec(dllimport) void __stdcall jump_rel(short dx, short dy);
_declspec(dllimport) void __stdcall n_jump_rel_3d(unsigned short n, short dx, short dy, short dz);
_declspec(dllimport) void __stdcall jump_rel_3d(short dx, short dy, short dz);
_declspec(dllimport) void __stdcall n_mark_rel(unsigned short n, short dx, short dy);
_declspec(dllimport) void __stdcall mark_rel(short dx, short dy);
_declspec(dllimport) void __stdcall n_mark_rel_3d(unsigned short n, short dx, short dy, short dz);
_declspec(dllimport) void __stdcall mark_rel_3d(short dx, short dy, short dz);
_declspec(dllimport) void __stdcall n_write_8bit_port_list(unsigned short n, unsigned short value);
_declspec(dllimport) void __stdcall write_8bit_port_list(unsigned short value);
_declspec(dllimport) void __stdcall n_write_da_1_list(unsigned short n, unsigned short value);
_declspec(dllimport) void __stdcall write_da_1_list(unsigned short value);
_declspec(dllimport) void __stdcall n_write_da_2_list(unsigned short n, unsigned short value);
_declspec(dllimport) void __stdcall write_da_2_list(unsigned short value);
_declspec(dllimport) void __stdcall n_write_da_x_list(unsigned short n, unsigned short x, unsigned short value);
_declspec(dllimport) void __stdcall write_da_x_list(unsigned short x, unsigned short value);
_declspec(dllimport) void __stdcall n_set_offset_list(unsigned short n, short xoffset, short yoffset);
_declspec(dllimport) void __stdcall set_offset_list(short xoffset, short yoffset);
_declspec(dllimport) void __stdcall n_long_delay(unsigned short n, unsigned short value);
_declspec(dllimport) void __stdcall long_delay(unsigned short value);
_declspec(dllimport) void __stdcall n_laser_on_list(unsigned short n, unsigned short value);
_declspec(dllimport) void __stdcall laser_on_list(unsigned short value);
_declspec(dllimport) void __stdcall n_set_jump_speed(unsigned short n, double speed);
_declspec(dllimport) void __stdcall set_jump_speed(double speed);
_declspec(dllimport) void __stdcall n_set_mark_speed(unsigned short n, double speed);
_declspec(dllimport) void __stdcall set_mark_speed(double speed);
_declspec(dllimport) void __stdcall n_set_laser_delays(unsigned short n, short ondelay, short offdelay);
_declspec(dllimport) void __stdcall set_laser_delays(short ondelay, short offdelay);
_declspec(dllimport) void __stdcall n_set_scanner_delays(unsigned short n, unsigned short jumpdelay, unsigned short markdelay, unsigned short polydelay);
_declspec(dllimport) void __stdcall set_scanner_delays(unsigned short jumpdelay, unsigned short markdelay, unsigned short polydelay);
_declspec(dllimport) void __stdcall n_set_list_jump(unsigned short n, long position);
_declspec(dllimport) void __stdcall set_list_jump(long position);
_declspec(dllimport) void __stdcall n_list_call(unsigned short n, long position);
_declspec(dllimport) void __stdcall list_call(long position);
_declspec(dllimport) void __stdcall n_list_return(unsigned short n);
_declspec(dllimport) void __stdcall list_return(void);
_declspec(dllimport) void __stdcall n_z_out_list(unsigned short n, short z);
_declspec(dllimport) void __stdcall z_out_list(short z);
_declspec(dllimport) void __stdcall n_set_standby_list(unsigned short n, unsigned short half_period, unsigned short pulse);
_declspec(dllimport) void __stdcall set_standby_list(unsigned short half_period, unsigned short pulse);
_declspec(dllimport) void __stdcall n_timed_jump_abs(unsigned short n, short x, short y, double time);
_declspec(dllimport) void __stdcall timed_jump_abs(short x, short y, double time);
_declspec(dllimport) void __stdcall n_timed_mark_abs(unsigned short n, short x, short y, double time);
_declspec(dllimport) void __stdcall timed_mark_abs(short x, short y, double time);
_declspec(dllimport) void __stdcall n_timed_jump_rel(unsigned short n, short dx, short dy, double time);
_declspec(dllimport) void __stdcall timed_jump_rel(short dx, short dy, double time);
_declspec(dllimport) void __stdcall n_timed_mark_rel(unsigned short n, short dx, short dy, double time);
_declspec(dllimport) void __stdcall timed_mark_rel(short dx, short dy, double time);
_declspec(dllimport) void __stdcall n_set_laser_timing(unsigned short n, unsigned short halfperiod, unsigned short pulse1, unsigned short pulse2, unsigned short timebase);
_declspec(dllimport) void __stdcall set_laser_timing(unsigned short halfperiod, unsigned short pulse1, unsigned short pulse2, unsigned short timebase);
_declspec(dllimport) void __stdcall n_set_wobbel(unsigned short n, unsigned short amplitude, double frequency);
_declspec(dllimport) void __stdcall set_wobbel(unsigned short amplitude, double frequency);
_declspec(dllimport) void __stdcall n_set_fly_x(unsigned short n, double kx);
_declspec(dllimport) void __stdcall set_fly_x(double kx);
_declspec(dllimport) void __stdcall n_set_fly_y(unsigned short n, double ky);
_declspec(dllimport) void __stdcall set_fly_y(double ky);
_declspec(dllimport) void __stdcall n_write_io_port_list(unsigned short n, unsigned short value);
_declspec(dllimport) void __stdcall write_io_port_list(unsigned short value);
_declspec(dllimport) void __stdcall n_set_wait(unsigned short n, unsigned short value);
_declspec(dllimport) void __stdcall set_wait(unsigned short value);
_declspec(dllimport) void __stdcall n_simulate_ext_start(unsigned short n, short delay, short encoder);
_declspec(dllimport) void __stdcall simulate_ext_start(short delay, short encoder);
_declspec(dllimport) void __stdcall n_set_pixel_line(unsigned short n, unsigned short pixelmode, unsigned short pixelperiod, double dx, double dy);
_declspec(dllimport) void __stdcall set_pixel_line(unsigned short pixelmode, unsigned short pixelperiod, double dx, double dy);
_declspec(dllimport) void __stdcall n_set_pixel(unsigned short n, unsigned short pulswidth, unsigned short davalue, unsigned short dummy);
_declspec(dllimport) void __stdcall set_pixel(unsigned short pulswidth, unsigned short davalue, unsigned short dummy);
_declspec(dllimport) void __stdcall n_set_extstartpos_list(unsigned short n, long position);
_declspec(dllimport) void __stdcall set_extstartpos_list(long position);
_declspec(dllimport) void __stdcall n_laser_signal_on_list(unsigned short n);
_declspec(dllimport) void __stdcall laser_signal_on_list(void);
_declspec(dllimport) void __stdcall n_laser_signal_off_list(unsigned short n);
_declspec(dllimport) void __stdcall laser_signal_off_list(void);
_declspec(dllimport) void __stdcall n_set_firstpulse_killer_list(unsigned short n, unsigned short fpk);
_declspec(dllimport) void __stdcall set_firstpulse_killer_list(unsigned short fpk);
_declspec(dllimport) void __stdcall n_set_io_cond_list(unsigned short n, unsigned short mask_1, unsigned short mask_0, unsigned short mask_set);
_declspec(dllimport) void __stdcall set_io_cond_list(unsigned short mask_1, unsigned short mask_0, unsigned short mask_set);
_declspec(dllimport) void __stdcall n_clear_io_cond_list(unsigned short n, unsigned short mask_1, unsigned short mask_0, unsigned short mask_clear);
_declspec(dllimport) void __stdcall clear_io_cond_list(unsigned short mask_1, unsigned short mask_0, unsigned short mask_clear);
_declspec(dllimport) void __stdcall n_list_jump_cond(unsigned short n, unsigned short mask_1, unsigned short mask_0, long position);
_declspec(dllimport) void __stdcall list_jump_cond(unsigned short mask_1, unsigned short mask_0, long position);
_declspec(dllimport) void __stdcall n_list_call_cond(unsigned short n, unsigned short mask_1, unsigned short mask_0, long position);
_declspec(dllimport) void __stdcall list_call_cond(unsigned short mask_1, unsigned short mask_0, long position);
_declspec(dllimport) void __stdcall n_save_and_restart_timer(unsigned short n);
_declspec(dllimport) void __stdcall save_and_restart_timer(void);
_declspec(dllimport) void __stdcall n_set_matrix_list(unsigned short n, unsigned short i, unsigned short j, double mij);
_declspec(dllimport) void __stdcall set_matrix_list(unsigned short i, unsigned short j, double mij);
_declspec(dllimport) void __stdcall n_set_control_mode_list(unsigned short n, unsigned short mode);
_declspec(dllimport) void __stdcall set_control_mode_list(unsigned short mode);
_declspec(dllimport) void __stdcall n_set_defocus_list(unsigned short n, short value);
_declspec(dllimport) void __stdcall set_defocus_list(short value);
_declspec(dllimport) void __stdcall n_set_ext_start_delay_list(unsigned short n, short delay, short encoder);
_declspec(dllimport) void __stdcall set_ext_start_delay_list(short delay, short encoder);
_declspec(dllimport) void __stdcall n_set_wobbel_xy(unsigned short n, unsigned short long_wob, unsigned short trans_wob, double frequency);
_declspec(dllimport) void __stdcall set_wobbel_xy(unsigned short long_wob, unsigned short trans_wob, double frequency);
_declspec(dllimport) void __stdcall n_calculate_fly(unsigned short n, unsigned short direction, double distance);
_declspec(dllimport) void __stdcall calculate_fly(unsigned short direction, double distance);
_declspec(dllimport) void __stdcall n_select_cor_table_list(unsigned short n, unsigned short heada, unsigned short headb);
_declspec(dllimport) void __stdcall select_cor_table_list(unsigned short heada, unsigned short headb);
_declspec(dllimport) void __stdcall n_set_fly_rot(unsigned short n, double resolution);
_declspec(dllimport) void __stdcall set_fly_rot(double resolution);
_declspec(dllimport) void __stdcall n_fly_return(unsigned short n, short x, short y);
_declspec(dllimport) void __stdcall fly_return(short x, short y);
_declspec(dllimport) void __stdcall n_set_trigger(unsigned short n, unsigned short sampleperiod, unsigned short channel1, unsigned short channel2);
_declspec(dllimport) void __stdcall set_trigger(unsigned short sampleperiod, unsigned short channel1, unsigned short channel2);
_declspec(dllimport) void __stdcall n_arc_rel(unsigned short n, short dx, short dy, double angle);
_declspec(dllimport) void __stdcall arc_rel(short dx, short dy, double angle);
_declspec(dllimport) void __stdcall n_arc_abs(unsigned short n, short x, short y, double angle);
_declspec(dllimport) void __stdcall arc_abs(short x, short y, double angle);
_declspec(dllimport) void __stdcall n_time_fix(unsigned short n);
_declspec(dllimport) void __stdcall time_fix(void);
_declspec(dllimport) void __stdcall n_time_fix_f(unsigned short n, unsigned short mode);
_declspec(dllimport) void __stdcall time_fix_f(unsigned short mode);
_declspec(dllimport) void __stdcall n_mark_time(unsigned short n, unsigned short part, unsigned short mode);
_declspec(dllimport) void __stdcall mark_time(unsigned short part, unsigned short mode);
_declspec(dllimport) void __stdcall n_mark_date(unsigned short n, unsigned short part, unsigned short mode);
_declspec(dllimport) void __stdcall mark_date(unsigned short part, unsigned short mode);
_declspec(dllimport) void __stdcall n_mark_serial(unsigned short n, unsigned short mode, unsigned short digits);
_declspec(dllimport) void __stdcall mark_serial(unsigned short mode, unsigned short digits);
_declspec(dllimport) void __stdcall n_date_check(unsigned short n, unsigned short month1, unsigned short month2, unsigned short month3);
_declspec(dllimport) void __stdcall date_check(unsigned short month1, unsigned short month2, unsigned short month3);
_declspec(dllimport) void __stdcall n_flyline(unsigned short n, short encoderdelay);
_declspec(dllimport) void __stdcall flyline(short encoderdelay);
_declspec(dllimport) void __stdcall n_drilling(unsigned short n, short pulsewidth, short relencoderdelay);
_declspec(dllimport) void __stdcall drilling(short pulsewidth, short relencoderdelay);
_declspec(dllimport) void __stdcall n_regulation(unsigned short n);
_declspec(dllimport) void __stdcall regulation(void);
_declspec(dllimport) void __stdcall n_store_encoder(unsigned short n);
_declspec(dllimport) void __stdcall store_encoder(void);
_declspec(dllimport) void __stdcall n_fly_displacement_ret(unsigned short n, short x, short y);
_declspec(dllimport) void __stdcall fly_displacement_ret(short x, short y);