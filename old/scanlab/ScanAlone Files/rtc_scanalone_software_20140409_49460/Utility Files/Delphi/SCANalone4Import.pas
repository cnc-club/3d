unit SCANalone4Import;
{
  Delphi Import Declarations for the 32 Bit SCANLAB SCANalone4-DLL
}
interface

const SCANalone4DLL = 'SCANalone4.DLL';

type
 Pint  = ^SmallInt;
 Pword = ^Word;

function  scanalone_count_cards: word; stdcall; external SCANalone4DLL;
procedure select_rtc(n: word); stdcall; external SCANalone4DLL;
procedure writemem(bn: word; adr: longint; n: word; memptr: pword); stdcall; external SCANalone4DLL;
procedure readmem(bn: word; adr: longint; n: word; var memptr: pword); stdcall; external SCANalone4DLL;
function  n_usb_status(n: word): longint; stdcall; external SCANalone4DLL;
function  usb_status: longint; stdcall; external SCANalone4DLL;
function  n_load_correction_file(n: word; filename: pchar; cortable: smallint; kx,ky,phi,xoffset,yoffset: double): smallint; stdcall; external SCANalone4DLL;
function  load_correction_file(filename: pchar; cortable: smallint; kx,ky,phi,xoffset,yoffset: double): smallint; stdcall; external SCANalone4DLL;
function  n_load_cor(n: word; filename: pchar): smallint; stdcall; external SCANalone4DLL;
function  load_cor(filename: pchar): smallint; stdcall; external SCANalone4DLL;
function  n_load_program_file(n: word; name: pchar): smallint; stdcall; external SCANalone4DLL;
function  load_program_file(name: pchar): smallint; stdcall; external SCANalone4DLL;
function  n_load_pro(n: word; filename: pchar): smallint; stdcall; external SCANalone4DLL;
function  load_pro(filename: pchar): smallint; stdcall; external SCANalone4DLL;
function  n_load_varpolydelay(n: word; stbfilename: pchar; tableno: word): smallint; stdcall; external SCANalone4DLL;
function  load_varpolydelay(stbfilename: pchar; tableno: word): smallint; stdcall; external SCANalone4DLL;
function  n_load_z_table(n: word; a,b,c: double): smallint; stdcall; external SCANalone4DLL;
function  load_z_table(a,b,c: double): smallint; stdcall; external SCANalone4DLL;
procedure n_get_waveform(n, channel, stopp:word; memptr:pint); stdcall; external SCANalone4DLL;
procedure get_waveform(channel,stopp:word; memptr:pint); stdcall; external SCANalone4DLL;
procedure n_get_status(n: word; var busy: wordbool; var position: longint); stdcall; external SCANalone4DLL;
procedure get_status(var busy: wordbool; var position: longint); stdcall; external SCANalone4DLL;
function  n_read_status(n: word): word; stdcall; external SCANalone4DLL;
function  read_status: word; stdcall; external SCANalone4DLL;
function  get_dll_version: word; stdcall; external SCANalone4DLL;
function  n_get_input_pointer(n: word): longint; stdcall; external SCANalone4DLL;
function  get_input_pointer: longint; stdcall; external SCANalone4DLL;
procedure n_set_input_pointer(n: word; pointer: longint); stdcall; external SCANalone4DLL;
procedure set_input_pointer(pointer: longint); stdcall; external SCANalone4DLL;
procedure n_set_start_list_1(n: word); stdcall; external SCANalone4DLL;
procedure set_start_list_1; stdcall; external SCANalone4DLL;
procedure n_set_start_list_2(n: word); stdcall; external SCANalone4DLL;
procedure set_start_list_2; stdcall; external SCANalone4DLL;
procedure n_set_start_list(n,listno: word); stdcall; external SCANalone4DLL;
procedure set_start_list(listno: word); stdcall; external SCANalone4DLL;
procedure n_execute_list_1(n: word); stdcall; external SCANalone4DLL;
procedure execute_list_1; stdcall; external SCANalone4DLL;
procedure n_execute_list_2(n: word); stdcall; external SCANalone4DLL;
procedure execute_list_2; stdcall; external SCANalone4DLL;
procedure n_execute_list(n,listno: word); stdcall; external SCANalone4DLL;
procedure execute_list(listno: word); stdcall; external SCANalone4DLL;
procedure n_write_8bit_port(n,value: word); stdcall; external SCANalone4DLL;
procedure write_8bit_port(value: word); stdcall; external SCANalone4DLL;
procedure n_write_io_port(n,value: word); stdcall; external SCANalone4DLL;
procedure write_io_port(value: word); stdcall; external SCANalone4DLL;
procedure n_auto_change(n: word); stdcall; external SCANalone4DLL;
procedure auto_change; stdcall; external SCANalone4DLL;
procedure n_aut_change(n: word); stdcall; external SCANalone4DLL;
procedure aut_change; stdcall; external SCANalone4DLL;
procedure n_start_loop(n: word); stdcall; external SCANalone4DLL;
procedure start_loop; stdcall; external SCANalone4DLL;
procedure n_quit_loop(n: word); stdcall; external SCANalone4DLL;
procedure quit_loop; stdcall; external SCANalone4DLL;
procedure n_stop_execution(n: word); stdcall; external SCANalone4DLL;
procedure stop_execution; stdcall; external SCANalone4DLL;
procedure n_dsp_start(n: word); stdcall; external SCANalone4DLL;
procedure dsp_start; stdcall; external SCANalone4DLL;
function  n_read_io_port(n: word): word; stdcall; external SCANalone4DLL;
function  read_io_port: word; stdcall; external SCANalone4DLL;
procedure n_write_da_1(n, value: word); stdcall; external SCANalone4DLL;
procedure write_da_1(value: word); stdcall; external SCANalone4DLL;
procedure n_write_da_2(n,value: word); stdcall; external SCANalone4DLL;
procedure write_da_2(value: word); stdcall; external SCANalone4DLL;
procedure n_write_da_x(n, x,value: word); stdcall; external SCANalone4DLL;
procedure write_da_x(x,value: word); stdcall; external SCANalone4DLL;
procedure n_set_max_counts(n: word; counts: longint); stdcall; external SCANalone4DLL;
procedure set_max_counts(counts: longint); stdcall; external SCANalone4DLL;
function  n_get_counts(n: word): longint; stdcall; external SCANalone4DLL;
function  get_counts: longint; stdcall; external SCANalone4DLL;
procedure n_set_matrix(n: word; m11,m12,m21,m22: double); stdcall; external SCANalone4DLL;
procedure set_matrix(m11,m12,m21,m22: double); stdcall; external SCANalone4DLL;
procedure n_set_offset(n: word; xoffset,yoffset: smallint); stdcall; external SCANalone4DLL;
procedure set_offset(xoffset,yoffset: smallint); stdcall; external SCANalone4DLL;
procedure n_goto_xy(n: word; x,y: smallint); stdcall; external SCANalone4DLL;
procedure goto_xy(x,y: smallint); stdcall; external SCANalone4DLL;
procedure n_goto_xyz(n: word; x,y,z: smallint); stdcall; external SCANalone4DLL;
procedure goto_xyz(x,y,z: smallint); stdcall; external SCANalone4DLL;
function  n_get_hex_version(n: word): word; stdcall; external SCANalone4DLL;
function  get_hex_version: word; stdcall; external SCANalone4DLL;
procedure n_enable_laser(n: word); stdcall; external SCANalone4DLL;
procedure enable_laser; stdcall; external SCANalone4DLL;
procedure n_disable_laser(n: word); stdcall; external SCANalone4DLL;
procedure disable_laser; stdcall; external SCANalone4DLL;
procedure n_stop_list(n: word); stdcall; external SCANalone4DLL;
procedure stop_list; stdcall; external SCANalone4DLL;
procedure n_restart_list(n: word); stdcall; external SCANalone4DLL;
procedure restart_list; stdcall; external SCANalone4DLL;
function  n_get_rtc_version(n: word): word; stdcall; external SCANalone4DLL;
function  get_rtc_version: word; stdcall; external SCANalone4DLL;
procedure n_get_xy_pos(n: word; var x,y: smallint); stdcall; external SCANalone4DLL;
procedure get_xy_pos(var x,y: smallint); stdcall; external SCANalone4DLL;
procedure n_get_xyz_pos(n: word; var x,y,z: smallint); stdcall; external SCANalone4DLL;
procedure get_xyz_pos(var x,y,z: smallint); stdcall; external SCANalone4DLL;
procedure n_select_list(n,list_2: word); stdcall; external SCANalone4DLL;
procedure select_list(list_2: word); stdcall; external SCANalone4DLL;
procedure n_set_extstartpos(n: word; position: longint); stdcall; external SCANalone4DLL;
procedure set_extstartpos(position: longint); stdcall; external SCANalone4DLL;
procedure n_z_out(n: word; z: smallint); stdcall; external SCANalone4DLL;
procedure z_out(z: smallint); stdcall; external SCANalone4DLL;
procedure n_set_firstpulse_killer(n, fpk: word); stdcall; external SCANalone4DLL;
procedure set_firstpulse_killer(fpk: word); stdcall; external SCANalone4DLL;
procedure n_set_standby(n, half_period, pulse: word); stdcall; external SCANalone4DLL;
procedure set_standby(half_period, pulse: word); stdcall; external SCANalone4DLL;
procedure n_laser_signal_on(n: word); stdcall; external SCANalone4DLL;
procedure laser_signal_on; stdcall; external SCANalone4DLL;
procedure n_laser_signal_off(n: word); stdcall; external SCANalone4DLL;
procedure laser_signal_off; stdcall; external SCANalone4DLL;
procedure n_set_delay_mode(n, varpoly,directmove3d,edgelevel,minjumpdelay,jumplengthlimit: word); stdcall; external SCANalone4DLL;
procedure set_delay_mode(varpoly,directmove3d,edgelevel,minjumpdelay,jumplengthlimit: word); stdcall; external SCANalone4DLL;
procedure n_set_piso_control(n, l1,l2: word); stdcall; external SCANalone4DLL;
procedure set_piso_control(l1,l2: word); stdcall; external SCANalone4DLL;
procedure n_select_status(n, mode: word); stdcall; external SCANalone4DLL;
procedure select_status(mode: word); stdcall; external SCANalone4DLL;
procedure n_get_encoder(n: word; var zx,zy: smallint); stdcall; external SCANalone4DLL;
procedure get_encoder(var zx,zy: smallint); stdcall; external SCANalone4DLL;
procedure n_select_cor_table(n,heada,headb: word); stdcall; external SCANalone4DLL;
procedure select_cor_table(heada,headb: word); stdcall; external SCANalone4DLL;
procedure n_execute_at_pointer(n: word; position: longint); stdcall; external SCANalone4DLL;
procedure execute_at_pointer(position: longint); stdcall; external SCANalone4DLL;
function  n_get_head_status(n,head: word): word; stdcall; external SCANalone4DLL;
function  get_head_status(head: word): word; stdcall; external SCANalone4DLL;
procedure n_simulate_encoder(n,channel: word); stdcall; external SCANalone4DLL;
procedure simulate_encoder(channel: word); stdcall; external SCANalone4DLL;
procedure n_release_wait(n: word); stdcall; external SCANalone4DLL;
procedure release_wait; stdcall; external SCANalone4DLL;
function  n_get_wait_status(n: word): word; stdcall; external SCANalone4DLL;
function  get_wait_status: word; stdcall; external SCANalone4DLL;
procedure n_set_control_mode(n,mode: word); stdcall; external SCANalone4DLL;
procedure set_control_mode(mode: word); stdcall; external SCANalone4DLL;
procedure n_set_laser_mode(n,mode: word); stdcall; external SCANalone4DLL;
procedure set_laser_mode(mode: word); stdcall; external SCANalone4DLL;
procedure n_set_ext_start_delay(n: word; delay,encoder: smallint); stdcall; external SCANalone4DLL;
procedure set_ext_start_delay(delay,encoder: smallint); stdcall; external SCANalone4DLL;
procedure n_home_position(n: word; xhome,yhome: smallint); stdcall; external SCANalone4DLL;
procedure home_position(xhome,yhome: smallint); stdcall; external SCANalone4DLL;
function  n_read_ad_x(n,x: word): word; stdcall; external SCANalone4DLL;
function  read_ad_x(x: word): word; stdcall; external SCANalone4DLL;
function  n_get_z_distance(n: word; x,y,z: smallint): smallint; stdcall; external SCANalone4DLL;
function  get_z_distance(x,y,z: smallint): smallint; stdcall; external SCANalone4DLL;
function  n_get_startstop_info(n: word): word; stdcall; external SCANalone4DLL;
function  get_startstop_info: word; stdcall; external SCANalone4DLL;
function  n_get_marking_info(n: word): word; stdcall; external SCANalone4DLL;
function  get_marking_info: word; stdcall; external SCANalone4DLL;
function  n_get_io_status(n: word): word; stdcall; external SCANalone4DLL;
function  get_io_status: word; stdcall; external SCANalone4DLL;
function  n_get_time(n: word): double; stdcall; external SCANalone4DLL;
function  get_time: double; stdcall; external SCANalone4DLL;
procedure n_set_defocus(n: word; value: smallint); stdcall; external SCANalone4DLL;
procedure set_defocus(value: smallint); stdcall; external SCANalone4DLL;
procedure n_set_softstart_mode(n, mode, number, restartdelay: word); stdcall; external SCANalone4DLL;
procedure set_softstart_mode(mode, number, restartdelay: word); stdcall; external SCANalone4DLL;
procedure n_set_softstart_level(n, index, level: word); stdcall; external SCANalone4DLL;
procedure set_softstart_level(index, level: word); stdcall; external SCANalone4DLL;
procedure n_control_command(n, head, axis, data: word); stdcall; external SCANalone4DLL;
procedure control_command(head, axis, data: word); stdcall; external SCANalone4DLL;
procedure n_set_rot_center(n: word; center_x,center_y: longint); stdcall; external SCANalone4DLL;
procedure set_rot_center(center_x,center_y: longint); stdcall; external SCANalone4DLL;
procedure n_auto_change_pos(n: word; start: longint); stdcall; external SCANalone4DLL;
procedure auto_change_pos(start: longint); stdcall; external SCANalone4DLL;
function  n_get_value(n,signal: word): smallint; stdcall; external SCANalone4DLL;
function  get_value(signal: word): smallint; stdcall; external SCANalone4DLL;
procedure n_set_io_bit(n, mask1: word); stdcall; external SCANalone4DLL;
procedure set_io_bit(mask1: word); stdcall; external SCANalone4DLL;
procedure n_clear_io_bit(n, mask0: word); stdcall; external SCANalone4DLL;
procedure clear_io_bit(mask0: word); stdcall; external SCANalone4DLL;
procedure n_set_duty_cycle_table(n,index, dutycycle: word); stdcall; external SCANalone4DLL;
procedure set_duty_cycle_table(index, dutycycle: word); stdcall; external SCANalone4DLL;
function  n_store_on_mmc(n: word): smallint; stdcall; external SCANalone4DLL;
function  store_on_mmc: smallint; stdcall; external SCANalone4DLL;
function  n_get_serial_number(n: word): word; stdcall; external SCANalone4DLL;
function  get_serial_number: word; stdcall; external SCANalone4DLL;
function  n_get_serial_number_32(n: word): longint; stdcall; external SCANalone4DLL;
function  get_serial_number_32: longint; stdcall; external SCANalone4DLL;
procedure n_measurement_status(n: word; var busy: wordbool; var position: word); stdcall; external SCANalone4DLL;
procedure measurement_status(var busy: wordbool; var position: word); stdcall; external SCANalone4DLL;
procedure n_clear_list(n: word); stdcall; external SCANalone4DLL;
procedure clear_list; stdcall; external SCANalone4DLL;
procedure n_set_char_table(n, ch: word; listpos: longint); stdcall; external SCANalone4DLL;
procedure set_char_table(ch: word; listpos: longint); stdcall; external SCANalone4DLL;
procedure n_time_update(n: word); stdcall; external SCANalone4DLL;
procedure time_update; stdcall; external SCANalone4DLL;
procedure n_set_serial(n: word; no: longint); stdcall; external SCANalone4DLL;
procedure set_serial(no: longint); stdcall; external SCANalone4DLL;
function  n_memory_test(n: word): longint; stdcall; external SCANalone4DLL;
function  memory_test: longint; stdcall; external SCANalone4DLL;
procedure n_list_nop(n: word); stdcall; external SCANalone4DLL;
procedure list_nop; stdcall; external SCANalone4DLL;
procedure n_set_end_of_list(n: word); stdcall; external SCANalone4DLL;
procedure set_end_of_list; stdcall; external SCANalone4DLL;
procedure n_jump_abs(n: word; x,y: smallint); stdcall; external SCANalone4DLL;
procedure jump_abs(x,y: smallint); stdcall; external SCANalone4DLL;
procedure n_jump_abs_3d(n: word; x,y,z: smallint); stdcall; external SCANalone4DLL;
procedure jump_abs_3d(x,y,z: smallint); stdcall; external SCANalone4DLL;
procedure n_mark_abs(n: word; x,y: smallint); stdcall; external SCANalone4DLL;
procedure mark_abs(x,y: smallint); stdcall; external SCANalone4DLL;
procedure n_mark_abs_3d(n: word; x,y,z: smallint); stdcall; external SCANalone4DLL;
procedure mark_abs_3d(x,y,z: smallint); stdcall; external SCANalone4DLL;
procedure n_jump_rel(n: word; dx,dy: smallint); stdcall; external SCANalone4DLL;
procedure jump_rel(dx,dy: smallint); stdcall; external SCANalone4DLL;
procedure n_jump_rel_3d(n: word; dx,dy,dz: smallint); stdcall; external SCANalone4DLL;
procedure jump_rel_3d(dx,dy,dz: smallint); stdcall; external SCANalone4DLL;
procedure n_mark_rel(n: word; dx,dy: smallint); stdcall; external SCANalone4DLL;
procedure mark_rel(dx,dy: smallint); stdcall; external SCANalone4DLL;
procedure n_mark_rel_3d(n: word; dx,dy,dz: smallint); stdcall; external SCANalone4DLL;
procedure mark_rel_3d(dx,dy,dz: smallint); stdcall; external SCANalone4DLL;
procedure n_write_8bit_port_list(n, value: word); stdcall; external SCANalone4DLL;
procedure write_8bit_port_list(value: word); stdcall; external SCANalone4DLL;
procedure n_write_da_1_list(n, value: word); stdcall; external SCANalone4DLL;
procedure write_da_1_list(value: word); stdcall; external SCANalone4DLL;
procedure n_write_da_2_list(n, value: word); stdcall; external SCANalone4DLL;
procedure write_da_2_list(value: word); stdcall; external SCANalone4DLL;
procedure n_write_da_x_list(n,x,value: word); stdcall; external SCANalone4DLL;
procedure write_da_x_list(x,value: word); stdcall; external SCANalone4DLL;
procedure n_set_offset_list(n: word; xoffset,yoffset: smallint); stdcall; external SCANalone4DLL;
procedure set_offset_list(xoffset,yoffset: smallint); stdcall; external SCANalone4DLL;
procedure n_long_delay(n,value: word); stdcall; external SCANalone4DLL;
procedure long_delay(value: word); stdcall; external SCANalone4DLL;
procedure n_laser_on_list(n, value: word); stdcall; external SCANalone4DLL;
procedure laser_on_list(value: word); stdcall; external SCANalone4DLL;
procedure n_set_jump_speed(n: word; speed: double); stdcall; external SCANalone4DLL;
procedure set_jump_speed(speed: double); stdcall; external SCANalone4DLL;
procedure n_set_mark_speed(n: word; speed: double); stdcall; external SCANalone4DLL;
procedure set_mark_speed(speed: double); stdcall; external SCANalone4DLL;
procedure n_set_laser_delays(n: word; ondelay,offdelay: smallint); stdcall; external SCANalone4DLL;
procedure set_laser_delays(ondelay,offdelay: smallint); stdcall; external SCANalone4DLL;
procedure n_set_scanner_delays(n, jumpdelay,markdelay,polydelay: word); stdcall; external SCANalone4DLL;
procedure set_scanner_delays(jumpdelay,markdelay,polydelay: word); stdcall; external SCANalone4DLL;
procedure n_set_list_jump(n: word; position: longint); stdcall; external SCANalone4DLL;
procedure set_list_jump(position: longint); stdcall; external SCANalone4DLL;
procedure n_list_call(n: word; position: longint); stdcall; external SCANalone4DLL;
procedure list_call(position: longint); stdcall; external SCANalone4DLL;
procedure n_list_return(n: word); stdcall; external SCANalone4DLL;
procedure list_return; stdcall; external SCANalone4DLL;
procedure n_z_out_list(n: word; z: smallint); stdcall; external SCANalone4DLL;
procedure z_out_list(z: smallint); stdcall; external SCANalone4DLL;
procedure n_set_standby_list(n, half_period, pulse: word); stdcall; external SCANalone4DLL;
procedure set_standby_list(half_period, pulse: word); stdcall; external SCANalone4DLL;
procedure n_timed_jump_abs(n: word; x,y: smallint; time: double); stdcall; external SCANalone4DLL;
procedure timed_jump_abs(x,y: smallint; time: double); stdcall; external SCANalone4DLL;
procedure n_timed_mark_abs(n: word; x,y: smallint; time: double); stdcall; external SCANalone4DLL;
procedure timed_mark_abs(x,y: smallint; time: double); stdcall; external SCANalone4DLL;
procedure n_timed_jump_rel(n: word; dx,dy: smallint; time: double); stdcall; external SCANalone4DLL;
procedure timed_jump_rel(dx,dy: smallint; time: double); stdcall; external SCANalone4DLL;
procedure n_timed_mark_rel(n: word; dx,dy: smallint; time: double); stdcall; external SCANalone4DLL;
procedure timed_mark_rel(dx,dy: smallint; time: double); stdcall; external SCANalone4DLL;
procedure n_set_laser_timing(n, halfperiod,pulse1,pulse2,timebase: word); stdcall; external SCANalone4DLL;
procedure set_laser_timing(halfperiod,pulse1,pulse2,timebase: word); stdcall; external SCANalone4DLL;
procedure n_set_wobbel(n, amplitude: word; frequency: double); stdcall; external SCANalone4DLL;
procedure set_wobbel(amplitude: word; frequency: double); stdcall; external SCANalone4DLL;
procedure n_set_fly_x(n: word; kx: double); stdcall; external SCANalone4DLL;
procedure set_fly_x(kx: double); stdcall; external SCANalone4DLL;
procedure n_set_fly_y(n: word; ky: double); stdcall; external SCANalone4DLL;
procedure set_fly_y(ky: double); stdcall; external SCANalone4DLL;
procedure n_write_io_port_list(n,value: word); stdcall; external SCANalone4DLL;
procedure write_io_port_list(value: word); stdcall; external SCANalone4DLL;
procedure n_set_wait(n,value: word); stdcall; external SCANalone4DLL;
procedure set_wait(value: word); stdcall; external SCANalone4DLL;
procedure n_simulate_ext_start(n: word; delay,encoder: smallint); stdcall; external SCANalone4DLL;
procedure simulate_ext_start(delay,encoder: smallint); stdcall; external SCANalone4DLL;
procedure n_set_pixel_line(n, pixelmode,pixelperiod: word; dx,dy: double); stdcall; external SCANalone4DLL;
procedure set_pixel_line(pixelmode,pixelperiod: word; dx,dy: double); stdcall; external SCANalone4DLL;
procedure n_set_pixel(n, pulswidth,davalue,dummy: word); stdcall; external SCANalone4DLL;
procedure set_pixel(pulswidth,davalue,dummy: word); stdcall; external SCANalone4DLL;
procedure n_set_extstartpos_list(n: word; position: longint); stdcall; external SCANalone4DLL;
procedure set_extstartpos_list(position: longint); stdcall; external SCANalone4DLL;
procedure n_laser_signal_on_list(n: word); stdcall; external SCANalone4DLL;
procedure laser_signal_on_list; stdcall; external SCANalone4DLL;
procedure n_laser_signal_off_list(n: word); stdcall; external SCANalone4DLL;
procedure laser_signal_off_list; stdcall; external SCANalone4DLL;
procedure n_set_firstpulse_killer_list(n,fpk: word); stdcall; external SCANalone4DLL;
procedure set_firstpulse_killer_list(fpk: word); stdcall; external SCANalone4DLL;
procedure n_set_io_cond_list(n, mask_1,mask_0,mask_set: word); stdcall; external SCANalone4DLL;
procedure set_io_cond_list(mask_1,mask_0,mask_set: word); stdcall; external SCANalone4DLL;
procedure n_clear_io_cond_list(n, mask_1,mask_0,mask_clear: word); stdcall; external SCANalone4DLL;
procedure clear_io_cond_list(mask_1,mask_0,mask_clear: word); stdcall; external SCANalone4DLL;
procedure n_list_jump_cond(n, mask_1,mask_0: word; position: longint); stdcall; external SCANalone4DLL;
procedure list_jump_cond(mask_1,mask_0: word; position: longint); stdcall; external SCANalone4DLL;
procedure n_list_call_cond(n, mask_1,mask_0: word; position: longint); stdcall; external SCANalone4DLL;
procedure list_call_cond(mask_1,mask_0: word; position: longint); stdcall; external SCANalone4DLL;
procedure n_save_and_restart_timer(n: word); stdcall; external SCANalone4DLL;
procedure save_and_restart_timer; stdcall; external SCANalone4DLL;
procedure n_set_matrix_list(n, i,j: word; mij: double); stdcall; external SCANalone4DLL;
procedure set_matrix_list(i,j: word; mij: double); stdcall; external SCANalone4DLL;
procedure n_set_control_mode_list(n,mode: word); stdcall; external SCANalone4DLL;
procedure set_control_mode_list(mode: word); stdcall; external SCANalone4DLL;
procedure n_set_defocus_list(n: word; value: smallint); stdcall; external SCANalone4DLL;
procedure set_defocus_list(value: smallint); stdcall; external SCANalone4DLL;
procedure n_set_ext_start_delay_list(n: word; delay,encoder: smallint); stdcall; external SCANalone4DLL;
procedure set_ext_start_delay_list(delay,encoder: smallint); stdcall; external SCANalone4DLL;
procedure n_set_wobbel_xy(n, long_wob,trans_wob: word; frequency: double); stdcall; external SCANalone4DLL;
procedure set_wobbel_xy(long_wob,trans_wob: word; frequency: double); stdcall; external SCANalone4DLL;
procedure n_calculate_fly(n, direction: word; distance: double); stdcall; external SCANalone4DLL;
procedure calculate_fly(direction: word; distance: double); stdcall; external SCANalone4DLL;
procedure n_select_cor_table_list(n,heada,headb: word); stdcall; external SCANalone4DLL;
procedure select_cor_table_list(heada,headb: word); stdcall; external SCANalone4DLL;
procedure n_set_fly_rot(n: word; resolution: double); stdcall; external SCANalone4DLL;
procedure set_fly_rot(resolution: double); stdcall; external SCANalone4DLL;
procedure n_fly_return(n: word; x,y: smallint); stdcall; external SCANalone4DLL;
procedure fly_return(x,y: smallint); stdcall; external SCANalone4DLL;
procedure n_set_trigger(n,sampleperiod,channel1,channel2: word); stdcall; external SCANalone4DLL;
procedure set_trigger(sampleperiod,channel1,channel2: word); stdcall; external SCANalone4DLL;
procedure n_arc_rel(n: word; dx,dy: smallint; angle: double); stdcall; external SCANalone4DLL;
procedure arc_rel(dx,dy: smallint; angle: double); stdcall; external SCANalone4DLL;
procedure n_arc_abs(n: word; x,y: smallint; angle: double); stdcall; external SCANalone4DLL;
procedure arc_abs(x,y: smallint; angle: double); stdcall; external SCANalone4DLL;
procedure n_time_fix(n: word); stdcall; external SCANalone4DLL;
procedure time_fix; stdcall; external SCANalone4DLL;
procedure n_time_fix_f(n,mode: word); stdcall; external SCANalone4DLL;
procedure time_fix_f(mode: word); stdcall; external SCANalone4DLL;
procedure n_mark_time(n,part,mode: word); stdcall; external SCANalone4DLL;
procedure mark_time(part,mode: word); stdcall; external SCANalone4DLL;
procedure n_mark_date(n,part,mode: word); stdcall; external SCANalone4DLL;
procedure mark_date(part,mode: word); stdcall; external SCANalone4DLL;
procedure n_mark_serial(n, mode, digits: word); stdcall; external SCANalone4DLL;
procedure mark_serial(mode, digits: word); stdcall; external SCANalone4DLL;
procedure n_date_check(n,month1,month2,month3: word); stdcall; external SCANalone4DLL;
procedure date_check(month1,month2,month3: word); stdcall; external SCANalone4DLL;
procedure n_flyline(n: word; encoderdelay: smallint); stdcall; external SCANalone4DLL;
procedure flyline(encoderdelay: smallint); stdcall; external SCANalone4DLL;
procedure n_drilling(n: word; pulsewidth, relencoderdelay: smallint); stdcall; external SCANalone4DLL;
procedure drilling(pulsewidth, relencoderdelay: smallint); stdcall; external SCANalone4DLL;
procedure n_regulation(n: word); stdcall; external SCANalone4DLL;
procedure regulation; stdcall; external SCANalone4DLL;
procedure n_store_encoder(n: word); stdcall; external SCANalone4DLL;
procedure store_encoder; stdcall; external SCANalone4DLL;
procedure n_fly_displacement_ret(n: word; x,y: smallint); stdcall; external SCANalone4DLL;
procedure fly_displacement_ret(x,y: smallint); stdcall; external SCANalone4DLL;

implementation

end.
