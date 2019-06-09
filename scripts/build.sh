#!/usr/bin/env bash

# Build "grpcweb/common" until it is updated regularly on Docker Hub

docker build -t grpcweb/common .

# Generate GRPC-Web client for `Core` service

PROTO_PATH="$PWD/protos"
CLIENTS_PATH="$PWD/clients"

WEB_OUT_PATH="$CLIENTS_PATH/web"

rm -rf "$WEB_OUT_PATH/*"

docker run -v "$PROTO_PATH:$PROTO_PATH" \
           -v "$WEB_OUT_PATH:$WEB_OUT_PATH" \
           --rm \
           grpcweb/common \
           protoc -I="$PROTO_PATH" "core.proto" \
                   --js_out="import_style=commonjs:$WEB_OUT_PATH" \
                   --grpc-web_out="import_style=commonjs,mode=grpcwebtext:$WEB_OUT_PATH"

# Generate GRPC-Web client for `TransactionsFilterStream` service

docker run -v "$PROTO_PATH:$PROTO_PATH" \
           -v "$WEB_OUT_PATH:$WEB_OUT_PATH" \
           --rm \
           grpcweb/common \
           protoc -I="$PROTO_PATH" "transactions_filter_stream.proto" \
                   --js_out="import_style=commonjs:$WEB_OUT_PATH" \
                   --grpc-web_out="import_style=commonjs,mode=grpcwebtext:$WEB_OUT_PATH"

# Copy generated messages for Node.JS client

rm -rf "$CLIENTS_PATH/node/*_pb.proto"
cp "$WEB_OUT_PATH/core_pb.js" "$CLIENTS_PATH/nodejs/"
cp "$WEB_OUT_PATH/transactions_filter_stream_pb.js" "$CLIENTS_PATH/nodejs/"

# Generate GRPC Java client for `Core`

JAVA_OUT_PATH="$CLIENTS_PATH/java"

rm -rf "$JAVA_OUT_PATH/*"

docker run -v "$PROTO_PATH:$PROTO_PATH" \
           -v "$JAVA_OUT_PATH:$JAVA_OUT_PATH" \
           --rm \
           znly/protoc \
           --plugin=protoc-gen-grpc=/usr/bin/protoc-gen-grpc-java \
           --grpc-java_out="$JAVA_OUT_PATH" \
           --proto_path="$PROTO_PATH" \
           -I "$PROTO_PATH" \
           "core.proto"

# Generate GRPC Java client for `TransactionsFilterStream`

docker run -v "$PROTO_PATH:$PROTO_PATH" \
           -v "$JAVA_OUT_PATH:$JAVA_OUT_PATH" \
           --rm \
           znly/protoc \
           --plugin=protoc-gen-grpc=/usr/bin/protoc-gen-grpc-java \
           --grpc-java_out="$JAVA_OUT_PATH" \
           --proto_path="$PROTO_PATH" \
           -I "$PROTO_PATH" \
           "transactions_filter_stream.proto"

# Generate GRPC Objective-C client for `Core`

OBJ_C_OUT_PATH="$CLIENTS_PATH/objective-c"

rm -rf "$OBJ_C_OUT_PATH/*"

docker run -v "$PROTO_PATH:$PROTO_PATH" \
           -v "$OBJ_C_OUT_PATH:$OBJ_C_OUT_PATH" \
           --rm \
           znly/protoc \
           --plugin=protoc-gen-grpc=/usr/bin/grpc_objective_c_plugin \
           --objc_out="$OBJ_C_OUT_PATH" \
           --grpc_out="$OBJ_C_OUT_PATH" \
           --proto_path="$PROTO_PATH" \
           -I "$PROTO_PATH" \
           "core.proto"

# Generate GRPC Objective-C client for `TransactionsFilterStream`

docker run -v "$PROTO_PATH:$PROTO_PATH" \
           -v "$OBJ_C_OUT_PATH:$OBJ_C_OUT_PATH" \
           --rm \
           znly/protoc \
           --plugin=protoc-gen-grpc=/usr/bin/grpc_objective_c_plugin \
           --objc_out="$OBJ_C_OUT_PATH" \
           --grpc_out="$OBJ_C_OUT_PATH" \
           --proto_path="$PROTO_PATH" \
           -I "$PROTO_PATH" \
           "transactions_filter_stream.proto"
