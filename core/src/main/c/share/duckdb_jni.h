#ifndef QUESTDB_DUCKDB_JNI_H
#define QUESTDB_DUCKDB_JNI_H

#include <jni.h>

extern "C" {
    // Error API
    JNIEXPORT jint JNICALL Java_io_questdb_duckdb_DuckDB_errorType(JNIEnv *, jclass);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_errorMessage(JNIEnv *, jclass);
    // Database API
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_databaseOpen(JNIEnv *env, jclass cs, jlong path_ptr, jlong path_size);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_databaseOpenExt(JNIEnv *env, jclass, jlong path_ptr, jlong path_size, jlong config_ptr);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_databaseClose(JNIEnv *, jclass, jlong db);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_databaseConnect(JNIEnv *env, jclass, jlong db);
    // Connection API
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_connectionInterrupt(JNIEnv *, jclass, jlong connection);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_connectionDisconnect(JNIEnv *, jclass, jlong connection);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_connectionQuery(JNIEnv *, jclass, jlong connection, jlong query_ptr, jlong query_size);
    // Configuration API
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_configCreate(JNIEnv *, jclass);
    JNIEXPORT jint JNICALL Java_io_questdb_duckdb_DuckDB_configSet(JNIEnv *, jclass, jlong config, jlong name_ptr, jlong name_size, jlong option_ptr, jlong option_size);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_configDestroy(JNIEnv *, jclass, jlong config);
    // Prepared Statement API
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_connectionPrepare(JNIEnv *, jclass, jlong connection, jlong query_ptr, jlong query_size);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_preparedExecute(JNIEnv *, jclass, jlong stmt);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_preparedDestroy(JNIEnv *, jclass, jlong stmt);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_preparedGetError(JNIEnv *, jclass, jlong stmt);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_preparedGetQueryText(JNIEnv *, jclass, jlong stmt);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_preparedGetStatementProperties(JNIEnv *, jclass, jlong stmt);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_preparedGetColumnCount(JNIEnv *, jclass, jlong stmt);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_preparedGetColumnTypes(JNIEnv *, jclass, jlong stmt, jlong col);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_preparedGetColumnName(JNIEnv *, jclass, jlong stmt, jlong col);
    // Result API
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_resultGetError(JNIEnv *, jclass, jlong result);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_resultFetchChunk(JNIEnv *, jclass, jlong result);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_resultDestroy(JNIEnv *, jclass, jlong result);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_resultColumnName(JNIEnv *, jclass, jlong result, jlong col);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_resultColumnTypes(JNIEnv *, jclass, jlong result, jlong col);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_resultColumnCount(JNIEnv *, jclass, jlong result);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_resultGetMaterialized(JNIEnv *, jclass, jlong result);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_resultRowCount(JNIEnv *, jclass, jlong result);
    JNIEXPORT jint JNICALL Java_io_questdb_duckdb_DuckDB_resultGetQueryResultType(JNIEnv *, jclass, jlong result);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_resultGetDataChunk(JNIEnv *, jclass, jlong result, jlong chunk_index);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_resultDataChunkCount(JNIEnv *, jclass, jlong result);
    // Data Chunk API
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_dataChunkDestroy(JNIEnv *, jclass, jlong chunk);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_dataChunkGetColumnCount(JNIEnv *, jclass, jlong chunk);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_dataChunkGetVector(JNIEnv *, jclass, jlong chunk, jlong col_idx);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_dataChunkGetSize(JNIEnv *, jclass, jlong chunk);
    // Vector API
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_vectorGetColumnTypes(JNIEnv *, jclass, jlong vector);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_vectorGetData(JNIEnv *, jclass, jlong vector);
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_vectorGetValidity(JNIEnv *, jclass, jlong vector);

    // Appender API
    JNIEXPORT jlong JNICALL Java_io_questdb_duckdb_DuckDB_createAppender(JNIEnv *, jclass, jlong conn, jlong schema_ptr,
        jlong schema_size, jlong table_ptr, jlong table_size);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_appenderBeginRow(JNIEnv *, jclass, jlong appender);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_appenderEndRow(JNIEnv *, jclass, jlong appender);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_appenderFlush(JNIEnv *, jclass, jlong appender);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_appenderClose(JNIEnv *, jclass, jlong appender);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_appenderAppendBoolean(JNIEnv *, jclass, jlong appender, jboolean value);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_appenderAppendByte(JNIEnv *, jclass, jlong appender, jbyte value);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_appenderAppendShort(JNIEnv *, jclass, jlong appender, jshort value);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_appenderAppendInt(JNIEnv *, jclass, jlong appender, jint value);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_appenderAppendDate(JNIEnv *, jclass, jlong appender, jint value);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_appenderAppendLong(JNIEnv *, jclass, jlong appender, jlong value);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_appenderAppendTimestamp(JNIEnv *, jclass, jlong appender, jlong value);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_appenderAppendLong128(JNIEnv *, jclass, jlong appender, jlong lo, jlong hi);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_appenderAppendUUID(JNIEnv *, jclass, jlong appender, jlong lo, jlong hi);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_appenderAppendFloat(JNIEnv *, jclass, jlong appender, jfloat value);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_appenderAppendDouble(JNIEnv *, jclass, jlong appender, jdouble value);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_appenderAppendUtf8StringOrBlob(JNIEnv *, jclass, jlong appender, jlong value_ptr, jlong value_size);
    JNIEXPORT void JNICALL Java_io_questdb_duckdb_DuckDB_appenderAppendNull(JNIEnv *, jclass, jlong appender);
}

#endif //QUESTDB_DUCKDB_JNI_H
