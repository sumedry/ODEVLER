docker events --filter 'event=die' --filter 'event=start' --format '{{json .}}' | ForEach-Object {
    $line = $_
    curl.exe -X POST http://localhost:5678/webhook/cbf941ac-9b3c-4b4f-9680-3dbcb77a6523 `
    -H "Content-Type: application/json" `
    -d "{\`"Baslik\`":\`"Docker_Monitor\`", \`"log_data\`": $line}"
}