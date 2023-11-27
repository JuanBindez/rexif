#include <stdio.h>
#include <exif-data.h>

void print_tag(ExifIfd ifd, ExifTag tag, ExifContent *content) {
    ExifEntry *entry = exif_content_get_entry(content, tag);
    if (entry) {
        char buf[1024];
        exif_entry_get_value(entry, buf, sizeof(buf));

        printf("Tag: %s, Value: %s\n", exif_tag_get_name(tag), buf);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];

    ExifData *exif = exif_data_new_from_file(filename);
    if (exif == NULL) {
        fprintf(stderr, "Failed to read EXIF data from %s\n", filename);
        return 1;
    }

    ExifContent *content = exif->ifd[EXIF_IFD_0];

    print_tag(EXIF_IFD_0, EXIF_TAG_MAKE, content);
    print_tag(EXIF_IFD_0, EXIF_TAG_MODEL, content);
    print_tag(EXIF_IFD_EXIF, EXIF_TAG_DATE_TIME_ORIGINAL, content);

    exif_data_free(exif);

    return 0;
}

