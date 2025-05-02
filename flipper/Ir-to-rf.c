#include <furi.h>
#include <gui/gui.h>
#include <infrared/infrared_worker.h>
#include <rf/rf_worker.h>
#include <storage/storage.h>
#include <lib/toolbox/path.h>
#include <lib/toolbox/stream/file_stream.h>

int32_t ir_rf_bridge_app(void* p) {
    furi_hal_power_enable_otg(); // Asegura que el módulo RF esté alimentado

    // Ruta al archivo IR que quieras enviar
    const char* ir_file_path = "/any/your_file.ir"; // Cámbialo por el tuyo
    uint8_t buffer[256];
    size_t bytes_read = 0;

    FileStream* stream = file_stream_alloc();
    if(file_stream_open(stream, ir_file_path, FSAM_READ, FSOM_OPEN_EXISTING)) {
        bytes_read = file_stream_read(stream, buffer, sizeof(buffer));
        file_stream_close(stream);
    }
    file_stream_free(stream);

    if(bytes_read > 0) {
        rf_worker_start();
        rf_worker_send_raw(buffer, bytes_read, 433920000);  // 433.92 MHz
        rf_worker_stop();
    }

    return 0;
}
