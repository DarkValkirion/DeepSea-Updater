/*
 * Copyright (c) 2018 naehrwert
 * Copyright (c) 2018-2019 CTCaer
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _DI_H_
#define _DI_H_

#include <memory_map.h>
#include <utils/types.h>

/*! Display registers. */
#define _DIREG(reg) ((reg) * 4)

// Display controller scratch registers.
#define DC_D_WINBUF_DD_SCRATCH_REGISTER_0 0xED
#define DC_D_WINBUF_DD_SCRATCH_REGISTER_1 0xEE
#define DC_T_WINBUF_TD_SCRATCH_REGISTER_0 0x16D
#define DC_T_WINBUF_TD_SCRATCH_REGISTER_1 0x16E
#define DC_COM_SCRATCH_REGISTER_A 0x325
#define DC_COM_SCRATCH_REGISTER_B 0x326
#define DC_A_WINBUF_AD_SCRATCH_REGISTER_0 0xBED
#define DC_A_WINBUF_AD_SCRATCH_REGISTER_1 0xBEE
#define DC_B_WINBUF_BD_SCRATCH_REGISTER_0 0xDED
#define DC_B_WINBUF_BD_SCRATCH_REGISTER_1 0xDEE
#define DC_C_WINBUF_CD_SCRATCH_REGISTER_0 0xFED
#define DC_C_WINBUF_CD_SCRATCH_REGISTER_1 0xFEE

// DC_CMD non-shadowed command/sync registers.
#define DC_CMD_GENERAL_INCR_SYNCPT 0x00

#define DC_CMD_GENERAL_INCR_SYNCPT_CNTRL 0x01
#define  SYNCPT_CNTRL_NO_STALL   (1 << 8)
#define  SYNCPT_CNTRL_SOFT_RESET (1 << 0)

#define DC_CMD_CONT_SYNCPT_VSYNC 0x28
#define  SYNCPT_VSYNC_ENABLE (1 << 8)

#define DC_CMD_DISPLAY_COMMAND_OPTION0 0x031

#define DC_CMD_DISPLAY_COMMAND 0x32
#define  DISP_CTRL_MODE_STOP       (0 << 5)
#define  DISP_CTRL_MODE_C_DISPLAY  (1 << 5)
#define  DISP_CTRL_MODE_NC_DISPLAY (2 << 5)
#define  DISP_CTRL_MODE_MASK       (3 << 5)

#define DC_CMD_DISPLAY_POWER_CONTROL 0x36
#define  PW0_ENABLE (1 <<  0)
#define  PW1_ENABLE (1 <<  2)
#define  PW2_ENABLE (1 <<  4)
#define  PW3_ENABLE (1 <<  6)
#define  PW4_ENABLE (1 <<  8)
#define  PM0_ENABLE (1 << 16)
#define  PM1_ENABLE (1 << 18)

#define DC_CMD_INT_STATUS 0x37
#define DC_CMD_INT_MASK 0x38
#define DC_CMD_INT_ENABLE 0x39

#define DC_CMD_STATE_ACCESS 0x40
#define  READ_MUX  (1 << 0)
#define  WRITE_MUX (1 << 2)

#define DC_CMD_STATE_CONTROL 0x41
#define  GENERAL_ACT_REQ (1 <<  0)
#define  WIN_A_ACT_REQ   (1 <<  1)
#define  WIN_B_ACT_REQ   (1 <<  2)
#define  WIN_C_ACT_REQ   (1 <<  3)
#define  WIN_D_ACT_REQ   (1 <<  4)
#define  CURSOR_ACT_REQ  (1 <<  7)
#define  GENERAL_UPDATE  (1 <<  8)
#define  WIN_A_UPDATE    (1 <<  9)
#define  WIN_B_UPDATE    (1 << 10)
#define  WIN_C_UPDATE    (1 << 11)
#define  WIN_D_UPDATE    (1 << 12)
#define  CURSOR_UPDATE   (1 << 15)
#define  NC_HOST_TRIG    (1 << 24)

#define DC_CMD_DISPLAY_WINDOW_HEADER 0x42
#define  WINDOW_A_SELECT (1 << 4)
#define  WINDOW_B_SELECT (1 << 5)
#define  WINDOW_C_SELECT (1 << 6)
#define  WINDOW_D_SELECT (1 << 7)

#define DC_CMD_REG_ACT_CONTROL 0x043

// DC_D_WIN_DD window D instance of DC_WIN
#define DC_D_WIN_DD_WIN_OPTIONS 0x80
#define DC_D_WIN_DD_COLOR_DEPTH 0x83
#define DC_D_WIN_DD_POSITION    0x84
#define DC_D_WIN_DD_SIZE        0x85
#define DC_D_WIN_DD_LINE_STRIDE 0x8A
#define DC_D_WIN_DD_BLEND_LAYER_CONTROL 0x96
#define DC_D_WIN_DD_BLEND_MATCH_SELECT  0x97
#define DC_D_WIN_DD_BLEND_ALPHA_1BIT    0x99

// DC_D_WINBUF_DD window D instance of DC_WINBUF
#define DC_D_WINBUF_DD_START_ADDR    0xC0
#define DC_D_WINBUF_DD_ADDR_H_OFFSET 0xC6
#define DC_D_WINBUF_DD_ADDR_V_OFFSET 0xC8
#define DC_D_WINBUF_DD_START_ADDR_HI 0xCD
#define DC_D_WINBUF_DD_MEMFETCH_CONTROL 0xEB

// DC_T_WIN_TD macro for using DD defines.
#define _DC_T(reg) ((reg) + 0x80)

// DC_COM non-shadowed registers.
#define DC_COM_CRC_CONTROL 0x300
#define DC_COM_PIN_OUTPUT_ENABLE(x) (0x302 + (x))
#define DC_COM_PIN_OUTPUT_POLARITY(x) (0x306 + (x))

#define DC_COM_DSC_TOP_CTL 0x33E

// DC_DISP shadowed registers.
#define DC_DISP_DISP_WIN_OPTIONS 0x402
#define  HDMI_ENABLE     (1 << 30)
#define  DSI_ENABLE      (1 << 29)
#define  SOR1_TIMING_CYA (1 << 27)
#define  SOR1_ENABLE     (1 << 26)
#define  SOR_ENABLE      (1 << 25)
#define  CURSOR_ENABLE   (1 << 16)

#define DC_DISP_DISP_MEM_HIGH_PRIORITY 0x403
#define DC_DISP_DISP_MEM_HIGH_PRIORITY_TIMER 0x404
#define DC_DISP_DISP_TIMING_OPTIONS 0x405
#define DC_DISP_REF_TO_SYNC 0x406
#define DC_DISP_SYNC_WIDTH 0x407
#define DC_DISP_BACK_PORCH 0x408
#define DC_DISP_ACTIVE 0x409
#define DC_DISP_FRONT_PORCH 0x40A

#define DC_DISP_DISP_CLOCK_CONTROL 0x42E
#define  PIXEL_CLK_DIVIDER_PCD1  (0 << 8)
#define  PIXEL_CLK_DIVIDER_PCD1H (1 << 8)
#define  PIXEL_CLK_DIVIDER_PCD2  (2 << 8)
#define  PIXEL_CLK_DIVIDER_PCD3  (3 << 8)
#define  PIXEL_CLK_DIVIDER_PCD4  (4 << 8)
#define  PIXEL_CLK_DIVIDER_PCD6  (5 << 8)
#define  PIXEL_CLK_DIVIDER_PCD8  (6 << 8)
#define  PIXEL_CLK_DIVIDER_PCD9  (7 << 8)
#define  PIXEL_CLK_DIVIDER_PCD12 (8 << 8)
#define  PIXEL_CLK_DIVIDER_PCD16 (9 << 8)
#define  PIXEL_CLK_DIVIDER_PCD18 (10 << 8)
#define  PIXEL_CLK_DIVIDER_PCD24 (11 << 8)
#define  PIXEL_CLK_DIVIDER_PCD13 (12 << 8)
#define  SHIFT_CLK_DIVIDER(x)    ((x) & 0xff)

#define DC_DISP_DISP_INTERFACE_CONTROL 0x42F
#define  DISP_DATA_FORMAT_DF1P1C    (0 << 0)
#define  DISP_DATA_FORMAT_DF1P2C24B (1 << 0)
#define  DISP_DATA_FORMAT_DF1P2C18B (2 << 0)
#define  DISP_DATA_FORMAT_DF1P2C16B (3 << 0)
#define  DISP_DATA_FORMAT_DF2S      (4 << 0)
#define  DISP_DATA_FORMAT_DF3S      (5 << 0)
#define  DISP_DATA_FORMAT_DFSPI     (6 << 0)
#define  DISP_DATA_FORMAT_DF1P3C24B (7 << 0)
#define  DISP_DATA_FORMAT_DF1P3C18B (8 << 0)
#define  DISP_ALIGNMENT_MSB         (0 << 8)
#define  DISP_ALIGNMENT_LSB         (1 << 8)
#define  DISP_ORDER_RED_BLUE        (0 << 9)
#define  DISP_ORDER_BLUE_RED        (1 << 9)

#define DC_DISP_DISP_COLOR_CONTROL 0x430
#define  DITHER_CONTROL_MASK    (3 << 8)
#define  DITHER_CONTROL_DISABLE (0 << 8)
#define  DITHER_CONTROL_ORDERED (2 << 8)
#define  DITHER_CONTROL_ERRDIFF (3 << 8)
#define  BASE_COLOR_SIZE_MASK   (0xf << 0)
#define  BASE_COLOR_SIZE_666    (0 << 0)
#define  BASE_COLOR_SIZE_111    (1 << 0)
#define  BASE_COLOR_SIZE_222    (2 << 0)
#define  BASE_COLOR_SIZE_333    (3 << 0)
#define  BASE_COLOR_SIZE_444    (4 << 0)
#define  BASE_COLOR_SIZE_555    (5 << 0)
#define  BASE_COLOR_SIZE_565    (6 << 0)
#define  BASE_COLOR_SIZE_332    (7 << 0)
#define  BASE_COLOR_SIZE_888    (8 << 0)

#define DC_DISP_SHIFT_CLOCK_OPTIONS 0x431
#define  SC1_H_QUALIFIER_NONE	(1 << 16)
#define  SC0_H_QUALIFIER_NONE	(1 <<  0)

#define DC_DISP_DATA_ENABLE_OPTIONS 0x432
#define  DE_SELECT_ACTIVE_BLANK  (0 << 0)
#define  DE_SELECT_ACTIVE        (1 << 0)
#define  DE_SELECT_ACTIVE_IS     (2 << 0)
#define  DE_CONTROL_ONECLK       (0 << 2)
#define  DE_CONTROL_NORMAL       (1 << 2)
#define  DE_CONTROL_EARLY_EXT    (2 << 2)
#define  DE_CONTROL_EARLY        (3 << 2)
#define  DE_CONTROL_ACTIVE_BLANK (4 << 2)

// Cursor configuration registers.
#define DC_DISP_CURSOR_FOREGROUND    0x43C
#define DC_DISP_CURSOR_BACKGROUND    0x43D
#define  CURSOR_COLOR(r,g,b) (((r) & 0xFF) | (((g) & 0xFF) << 8) | (((b) & 0xFF) << 16))

#define DC_DISP_CURSOR_START_ADDR    0x43E
#define  CURSOR_CLIPPING(w) ((w) << 28)
#define   CURSOR_CLIP_WIN_A 1
#define   CURSOR_CLIP_WIN_B 2
#define   CURSOR_CLIP_WIN_C 3
#define  CURSOR_SIZE_32  (0 << 24)
#define  CURSOR_SIZE_64  (1 << 24)
#define  CURSOR_SIZE_128 (2 << 24)
#define  CURSOR_SIZE_256 (3 << 24)
#define DC_DISP_CURSOR_POSITION      0x440
#define DC_DISP_CURSOR_START_ADDR_HI 0x4EC
#define DC_DISP_BLEND_CURSOR_CONTROL 0x4F1
#define  CURSOR_BLEND_2BIT     (0 << 24)
#define  CURSOR_BLEND_R8G8B8A8 (1 << 24)
#define  CURSOR_BLEND_SRC_FACTOR(n) ((n) << 8)
#define  CURSOR_BLEND_DST_FACTOR(n) ((n) << 16)
#define   CURSOR_BLEND_ZRO 0
#define   CURSOR_BLEND_K1  1
#define   CURSOR_BLEND_NK1 2
// End of cursor cfg regs.

#define DC_DISP_DC_MCCIF_FIFOCTRL 0x480
#define DC_DISP_SD_BL_PARAMETERS 0x4D7
#define DC_DISP_SD_BL_CONTROL 0x4DC
#define DC_DISP_BLEND_BACKGROUND_COLOR 0x4E4

#define DC_WIN_CSC_YOF 0x611
#define DC_WIN_CSC_KYRGB 0x612
#define DC_WIN_CSC_KUR 0x613
#define DC_WIN_CSC_KVR 0x614
#define DC_WIN_CSC_KUG 0x615
#define DC_WIN_CSC_KVG 0x616
#define DC_WIN_CSC_KUB 0x617
#define DC_WIN_CSC_KVB 0x618
#define DC_WIN_AD_WIN_OPTIONS 0xB80
#define DC_WIN_BD_WIN_OPTIONS 0xD80
#define DC_WIN_CD_WIN_OPTIONS 0xF80

// The following registers are A/B/C shadows of the 0xB80/0xD80/0xF80 registers (see DISPLAY_WINDOW_HEADER).
#define DC_WIN_WIN_OPTIONS 0x700
#define  H_DIRECTION  (1 <<  0)
#define  V_DIRECTION  (1 <<  2)
#define  SCAN_COLUMN  (1 <<  4)
#define  COLOR_EXPAND (1 <<  6)
#define  CSC_ENABLE   (1 << 18)
#define  WIN_ENABLE   (1 << 30)

#define DC_WIN_BUFFER_CONTROL 0x702
#define  BUFFER_CONTROL_HOST  0
#define  BUFFER_CONTROL_VI    1
#define  BUFFER_CONTROL_EPP   2
#define  BUFFER_CONTROL_MPEGE 3
#define  BUFFER_CONTROL_SB2D  4

#define DC_WIN_COLOR_DEPTH 0x703
#define  WIN_COLOR_DEPTH_P1             0x0
#define  WIN_COLOR_DEPTH_P2             0x1
#define  WIN_COLOR_DEPTH_P4             0x2
#define  WIN_COLOR_DEPTH_P8             0x3
#define  WIN_COLOR_DEPTH_B4G4R4A4       0x4
#define  WIN_COLOR_DEPTH_B5G5R5A        0x5
#define  WIN_COLOR_DEPTH_B5G6R5         0x6
#define  WIN_COLOR_DEPTH_AB5G5R5        0x7
#define  WIN_COLOR_DEPTH_B8G8R8A8       0xC
#define  WIN_COLOR_DEPTH_R8G8B8A8       0xD
#define  WIN_COLOR_DEPTH_B6x2G6x2R6x2A8 0xE
#define  WIN_COLOR_DEPTH_R6x2G6x2B6x2A8 0xF
#define  WIN_COLOR_DEPTH_YCbCr422       0x10
#define  WIN_COLOR_DEPTH_YUV422         0x11
#define  WIN_COLOR_DEPTH_YCbCr420P      0x12
#define  WIN_COLOR_DEPTH_YUV420P        0x13
#define  WIN_COLOR_DEPTH_YCbCr422P      0x14
#define  WIN_COLOR_DEPTH_YUV422P        0x15
#define  WIN_COLOR_DEPTH_YCbCr422R      0x16
#define  WIN_COLOR_DEPTH_YUV422R        0x17
#define  WIN_COLOR_DEPTH_YCbCr422RA     0x18
#define  WIN_COLOR_DEPTH_YUV422RA       0x19

#define DC_WIN_POSITION 0x704
#define  H_POSITION(x) (((x) & 0xFfff) <<  0)
#define  V_POSITION(x) (((x) & 0x1fff) << 16)

#define DC_WIN_SIZE 0x705
#define  H_SIZE(x) (((x) & 0x1fff) <<  0)
#define  V_SIZE(x) (((x) & 0x1fff) << 16)

#define DC_WIN_PRESCALED_SIZE 0x706
#define  H_PRESCALED_SIZE(x) (((x) & 0x7fff) <<  0)
#define  V_PRESCALED_SIZE(x) (((x) & 0x1fff) << 16)

#define DC_WIN_H_INITIAL_DDA 0x707
#define DC_WIN_V_INITIAL_DDA 0x708

#define DC_WIN_DDA_INC 0x709
#define  H_DDA_INC(x) (((x) & 0xffff) <<  0)
#define  V_DDA_INC(x) (((x) & 0xffff) << 16)

#define DC_WIN_LINE_STRIDE 0x70A
#define  LINE_STRIDE(x)	   (x)
#define  UV_LINE_STRIDE(x) (((x) & 0xffff) << 16)
#define DC_WIN_DV_CONTROL 0x70E

#define DC_WINBUF_BLEND_LAYER_CONTROL 0x716
#define  WIN_K1(x) (((x) & 0xff) << 8)
#define  WIN_K2(x) (((x) & 0xff) << 16)
#define  WIN_BLEND_ENABLE (0 << 24)
#define  WIN_BLEND_BYPASS (1 << 24)

#define DC_WINBUF_BLEND_MATCH_SELECT 0x717
#define  WIN_BLEND_FACT_SRC_COLOR_MATCH_SEL_ZERO             (0 << 0)
#define  WIN_BLEND_FACT_SRC_COLOR_MATCH_SEL_ONE              (1 << 0)
#define  WIN_BLEND_FACT_SRC_COLOR_MATCH_SEL_K1               (2 << 0)
#define  WIN_BLEND_FACT_SRC_COLOR_MATCH_SEL_K1_TIMES_DST     (3 << 0)
#define  WIN_BLEND_FACT_SRC_COLOR_MATCH_SEL_NEG_K1_TIMES_DST (4 << 0)
#define  WIN_BLEND_FACT_SRC_COLOR_MATCH_SEL_K1_TIMES_SRC     (5 << 0)

#define  WIN_BLEND_FACT_DST_COLOR_MATCH_SEL_ZERO             (0 << 4)
#define  WIN_BLEND_FACT_DST_COLOR_MATCH_SEL_ONE              (1 << 4)
#define  WIN_BLEND_FACT_DST_COLOR_MATCH_SEL_K1               (2 << 4)
#define  WIN_BLEND_FACT_DST_COLOR_MATCH_SEL_K2               (3 << 4)
#define  WIN_BLEND_FACT_DST_COLOR_MATCH_SEL_K1_TIMES_DST     (4 << 4)
#define  WIN_BLEND_FACT_DST_COLOR_MATCH_SEL_NEG_K1_TIMES_DST (5 << 4)
#define  WIN_BLEND_FACT_DST_COLOR_MATCH_SEL_NEG_K1_TIMES_SRC (6 << 4)
#define  WIN_BLEND_FACT_DST_COLOR_MATCH_SEL_NEG_K1           (7 << 4)

#define  WIN_BLEND_FACT_SRC_ALPHA_MATCH_SEL_ZERO             (0 << 8)
#define  WIN_BLEND_FACT_SRC_ALPHA_MATCH_SEL_K1               (1 << 8)
#define  WIN_BLEND_FACT_SRC_ALPHA_MATCH_SEL_K2               (2 << 8)

#define  WIN_BLEND_FACT_DST_ALPHA_MATCH_SEL_ZERO             (0 << 12)
#define  WIN_BLEND_FACT_DST_ALPHA_MATCH_SEL_ONE              (1 << 12)
#define  WIN_BLEND_FACT_DST_ALPHA_MATCH_SEL_NEG_K1_TIMES_SRC (2 << 12)
#define  WIN_BLEND_FACT_DST_ALPHA_MATCH_SEL_K2               (3 << 12)

#define DC_WINBUF_BLEND_ALPHA_1BIT 0x719
#define  WIN_ALPHA_1BIT_WEIGHT0(x) (((x) & 0xff) << 0)
#define  WIN_ALPHA_1BIT_WEIGHT1(x) (((x) & 0xff) << 8)

/*! The following registers are A/B/C shadows of the 0xBC0/0xDC0/0xFC0 registers (see DISPLAY_WINDOW_HEADER). */
#define DC_WINBUF_START_ADDR 0x800
#define DC_WINBUF_ADDR_H_OFFSET 0x806
#define DC_WINBUF_ADDR_V_OFFSET 0x808
#define DC_WINBUF_SURFACE_KIND 0x80B
#define  PITCH	(0 << 0)
#define  TILED	(1 << 0)
#define  BLOCK	(2 << 0)
#define  BLOCK_HEIGHT(x) (((x) & 0x7) << 4)

/*! Display serial interface registers. */
#define _DSIREG(reg) ((reg) * 4)

#define DSI_RD_DATA 0x9
#define DSI_WR_DATA 0xA

#define DSI_POWER_CONTROL 0xB
#define  DSI_POWER_CONTROL_ENABLE 1

#define DSI_INT_ENABLE 0xC
#define DSI_INT_STATUS 0xD
#define DSI_INT_MASK 0xE

#define DSI_HOST_CONTROL 0xF
#define  DSI_HOST_CONTROL_FIFO_RESET   (1 << 21)
#define  DSI_HOST_CONTROL_CRC_RESET    (1 << 20)
#define  DSI_HOST_CONTROL_TX_TRIG_SOL  (0 << 12)
#define  DSI_HOST_CONTROL_TX_TRIG_FIFO (1 << 12)
#define  DSI_HOST_CONTROL_TX_TRIG_HOST (2 << 12)
#define  DSI_HOST_CONTROL_RAW          (1 << 6)
#define  DSI_HOST_CONTROL_HS           (1 << 5)
#define  DSI_HOST_CONTROL_FIFO_SEL     (1 << 4)
#define  DSI_HOST_CONTROL_IMM_BTA      (1 << 3)
#define  DSI_HOST_CONTROL_PKT_BTA      (1 << 2)
#define  DSI_HOST_CONTROL_CS           (1 << 1)
#define  DSI_HOST_CONTROL_ECC          (1 << 0)

#define DSI_CONTROL 0x10
#define  DSI_CONTROL_HS_CLK_CTRL  (1 << 20)
#define  DSI_CONTROL_CHANNEL(c)   (((c) & 0x3) << 16)
#define  DSI_CONTROL_FORMAT(f)    (((f) & 0x3) << 12)
#define  DSI_CONTROL_TX_TRIG(x)   (((x) & 0x3) <<  8)
#define  DSI_CONTROL_LANES(n)     (((n) & 0x3) <<  4)
#define  DSI_CONTROL_DCS_ENABLE   (1 << 3)
#define  DSI_CONTROL_SOURCE(s)    (((s) & 0x1) <<  2)
#define  DSI_CONTROL_VIDEO_ENABLE (1 << 1)
#define  DSI_CONTROL_HOST_ENABLE  (1 << 0)

#define DSI_SOL_DELAY 0x11
#define DSI_MAX_THRESHOLD 0x12

#define DSI_TRIGGER 0x13
#define  DSI_TRIGGER_HOST  (1 << 1)
#define  DSI_TRIGGER_VIDEO (1 << 0)

#define DSI_TX_CRC 0x14
#define DSI_STATUS 0x15
#define DSI_INIT_SEQ_CONTROL 0x1A
#define DSI_INIT_SEQ_DATA_0 0x1B
#define DSI_INIT_SEQ_DATA_1 0x1C
#define DSI_INIT_SEQ_DATA_2 0x1D
#define DSI_INIT_SEQ_DATA_3 0x1E
#define DSI_PKT_SEQ_0_LO 0x23
#define DSI_PKT_SEQ_0_HI 0x24
#define DSI_PKT_SEQ_1_LO 0x25
#define DSI_PKT_SEQ_1_HI 0x26
#define DSI_PKT_SEQ_2_LO 0x27
#define DSI_PKT_SEQ_2_HI 0x28
#define DSI_PKT_SEQ_3_LO 0x29
#define DSI_PKT_SEQ_3_HI 0x2A
#define DSI_PKT_SEQ_4_LO 0x2B
#define DSI_PKT_SEQ_4_HI 0x2C
#define DSI_PKT_SEQ_5_LO 0x2D
#define DSI_PKT_SEQ_5_HI 0x2E
#define DSI_DCS_CMDS 0x33
#define DSI_PKT_LEN_0_1 0x34
#define DSI_PKT_LEN_2_3 0x35
#define DSI_PKT_LEN_4_5 0x36
#define DSI_PKT_LEN_6_7 0x37
#define DSI_PHY_TIMING_0 0x3C
#define DSI_PHY_TIMING_1 0x3D
#define DSI_PHY_TIMING_2 0x3E
#define DSI_BTA_TIMING 0x3F

#define DSI_TIMEOUT_0 0x44
#define  DSI_TIMEOUT_LRX(x) (((x) & 0xffff) << 16)
#define  DSI_TIMEOUT_HTX(x) (((x) & 0xffff) <<  0)

#define DSI_TIMEOUT_1 0x45
#define  DSI_TIMEOUT_PR(x) (((x) & 0xffff) << 16)
#define  DSI_TIMEOUT_TA(x) (((x) & 0xffff) <<  0)

#define DSI_TO_TALLY 0x46

#define DSI_PAD_CONTROL_0 0x4B
#define  DSI_PAD_CONTROL_VS1_PULLDN_CLK (1 << 24)
#define  DSI_PAD_CONTROL_VS1_PULLDN(x)  (((x) & 0xf) << 16)
#define  DSI_PAD_CONTROL_VS1_PDIO_CLK   (1 <<  8)
#define  DSI_PAD_CONTROL_VS1_PDIO(x)    (((x) & 0xf) <<  0)

#define DSI_PAD_CONTROL_CD 0x4C
#define DSI_VIDEO_MODE_CONTROL 0x4E
#define  DSI_CMD_PKT_VID_ENABLE 1

#define DSI_PAD_CONTROL_1 0x4F
#define DSI_PAD_CONTROL_2 0x50

#define DSI_PAD_CONTROL_3 0x51
#define  DSI_PAD_PREEMP_PD_CLK(x) (((x) & 0x3) << 12)
#define  DSI_PAD_PREEMP_PU_CLK(x) (((x) & 0x3) << 8)
#define  DSI_PAD_PREEMP_PD(x)     (((x) & 0x3) << 4)
#define  DSI_PAD_PREEMP_PU(x)     (((x) & 0x3) << 0)

#define DSI_PAD_CONTROL_4 0x52
#define DSI_INIT_SEQ_DATA_15 0x5F

/*! MIPI registers. */
#define MIPI_CAL_MIPI_CAL_CTRL          (0x00 / 0x4)
#define MIPI_CAL_CIL_MIPI_CAL_STATUS    (0x08 / 0x4)
#define MIPI_CAL_CILA_MIPI_CAL_CONFIG   (0x14 / 0x4)
#define MIPI_CAL_CILB_MIPI_CAL_CONFIG   (0x18 / 0x4)
#define MIPI_CAL_CILC_MIPI_CAL_CONFIG   (0x1C / 0x4)
#define MIPI_CAL_CILD_MIPI_CAL_CONFIG   (0x20 / 0x4)
#define MIPI_CAL_CILE_MIPI_CAL_CONFIG   (0x24 / 0x4)
#define MIPI_CAL_CILF_MIPI_CAL_CONFIG   (0x28 / 0x4)
#define MIPI_CAL_DSIA_MIPI_CAL_CONFIG   (0x38 / 0x4)
#define MIPI_CAL_DSIB_MIPI_CAL_CONFIG   (0x3C / 0x4)
#define MIPI_CAL_DSIC_MIPI_CAL_CONFIG   (0x40 / 0x4)
#define MIPI_CAL_DSID_MIPI_CAL_CONFIG   (0x44 / 0x4)
#define MIPI_CAL_MIPI_BIAS_PAD_CFG0     (0x58 / 0x4)
#define MIPI_CAL_MIPI_BIAS_PAD_CFG1     (0x5C / 0x4)
#define MIPI_CAL_MIPI_BIAS_PAD_CFG2     (0x60 / 0x4)
#define MIPI_CAL_DSIA_MIPI_CAL_CONFIG_2 (0x64 / 0x4)
#define MIPI_CAL_DSIB_MIPI_CAL_CONFIG_2 (0x68 / 0x4)
#define MIPI_CAL_DSIC_MIPI_CAL_CONFIG_2 (0x70 / 0x4)
#define MIPI_CAL_DSID_MIPI_CAL_CONFIG_2 (0x74 / 0x4)

/*! MIPI CMDs. */
#define MIPI_DSI_DCS_SHORT_WRITE 0x05
#define MIPI_DSI_DCS_READ 0x06
#define MIPI_DSI_DCS_SHORT_WRITE_PARAM 0x15
#define MIPI_DSI_SET_MAXIMUM_RETURN_PACKET_SIZE 0x37
#define MIPI_DSI_DCS_LONG_WRITE 0x39

/*! MIPI DCS CMDs. */
#define MIPI_DCS_GET_DISPLAY_ID   0x04
#define MIPI_DCS_ENTER_SLEEP_MODE 0x10
#define MIPI_DCS_EXIT_SLEEP_MODE  0x11
#define MIPI_DCS_SET_DISPLAY_ON   0x29

/* Switch Panels:
 *
 * 6.2 panels":
 * [10] 81 [26]: JDI LPM062M326A
 * [10] 96 [09]: JDI LAM062M109A
 * [20] 93 [0F]: InnoLux P062CCA-AZ1 (Rev A1)
 * [20] 95 [0F]: InnoLux P062CCA-AZ2
 * [30] 94 [0F]: AUO A062TAN01 (59.06A33.001)
 * [30] 95 [0F]: AUO A062TAN02 (59.06A33.002)
 *
 * 5.5" panels:
 * [20] 94 [10]: InnoLux 2J055IA-27A (Rev B1)
 * [30] XX [10]: AUO A055TAN01 (59.05A30.001) [UNCONFIRMED ID]
 */

enum
{
	PANEL_JDI_XXX062M     = 0x10,
	PANEL_JDI_LAM062M109A = 0x0910,
	PANEL_JDI_LPM062M326A = 0x2610,
	PANEL_INL_P062CCA_AZ1 = 0x0F20,
	PANEL_AUO_A062TAN01   = 0x0F30,
	PANEL_INL_2J055IA_27A = 0x1020,
	PANEL_AUO_A055TAN01   = 0x1030
};

void display_init();
void display_backlight_pwm_init();
void display_end();

/*! Show one single color on the display. */
void display_color_screen(u32 color);

/*! Switches screen backlight ON/OFF. */
void display_backlight(bool enable);
void display_backlight_brightness(u32 brightness, u32 step_delay);

/*! Init display in full 1280x720 resolution (B8G8R8A8, line stride 768, framebuffer size = 1280*768*4 bytes). */
u32 *display_init_framebuffer_pitch();
u32 *display_init_framebuffer_pitch_inv();
u32 *display_init_framebuffer_block();
u32 *display_init_framebuffer_log();
void display_activate_console();
void display_deactivate_console();
void display_init_cursor(void *crs_fb, u32 size);
void display_set_pos_cursor(u32 x, u32 y);
void display_deinit_cursor();

#endif
