#include "ES8388AudioSink.h"

#include "driver/i2s.h"

ES8388AudioSink::ES8388AudioSink()
{
    i2s_config_t i2s_config = {

        .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX), // Only TX
        .sample_rate = 44100,
        .bits_per_sample = (i2s_bits_per_sample_t)16,
        .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT, //2-channels
        .communication_format = (i2s_comm_format_t)I2S_COMM_FORMAT_STAND_MSB,
        .intr_alloc_flags = 0, //Default interrupt priority
        .dma_buf_count = 8,
        .dma_buf_len = 512,
        .use_apll = true,
        .tx_desc_auto_clear = true, //Auto clear tx descriptor on underflow
        .fixed_mclk = 0
    };

    i2s_pin_config_t pin_config = {
        .bck_io_num = 5,
        .ws_io_num = 25,
        .data_out_num = 26,
        .data_in_num = -1 //Not used
    };
    i2s_driver_install((i2s_port_t)0, &i2s_config, 0, NULL);
    i2s_set_pin((i2s_port_t)0, &pin_config);
    
    PIN_FUNC_SELECT(PERIPHS_IO_MUX_GPIO0_U, FUNC_GPIO0_CLK_OUT1);
    REG_SET_FIELD(PIN_CTRL, CLK_OUT1, 0);
    ESP_LOGI("OI", "MCLK output on CLK_OUT1");

    ESP_LOGI("OI", "Start audio codec chip");
    audio_board_handle_t board_handle = audio_board_init();
    audio_hal_ctrl_codec(board_handle->audio_hal, AUDIO_HAL_CODEC_MODE_DECODE, AUDIO_HAL_CTRL_START);
    
    startI2sFeed();
}

ES8388AudioSink::~ES8388AudioSink()
{
}
