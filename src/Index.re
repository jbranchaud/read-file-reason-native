switch (Unix.openfile("my-file.txt", [Unix.O_RDONLY], 0)) {
| exception (Unix.Unix_error(Unix.ENOENT, _action, filename)) =>
  print_endline("No such file or directory: " ++ filename)
| file =>
  /* determine number of bytes in the file */
  let file_stats = Unix.fstat(file);
  let bytes_to_read = file_stats.st_size;

  /* read the file into the byte buffer */
  let bytes = Bytes.create(bytes_to_read);
  let _byte_count = Unix.read(file, bytes, 0, bytes_to_read);
  print_endline("Bytes Read: " ++ Bytes.to_string(bytes));

  Unix.close(file);
};